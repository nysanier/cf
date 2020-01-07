#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (long i = x; i < n+x; ++i)
#define fornr(i, x, n) for (long i = n-1+x; i >= x; --i)  // must be signed, or 0->~0
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (long i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (long i = y; i >= x; i -= d)
#define forxy(i, x, y) forxyd(i, x, y, 1)
#define foryx(i, x, y) foryxd(i, x, y, 1)
#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

// type
// using ll = int32_t;
using ll = int64_t;
using Vec = std::vector<ll>;
using Deq = std::deque<ll>;
using Lst = std::list<ll>;
using Pr = std::pair<ll, ll>;
using St = std::set<ll>;
using Mst = std::multiset<ll>;
using Ust = std::unordered_set<ll>;
using Mp = std::map<ll, ll>;
using Mmp = std::multimap<ll, ll>;
using Ump = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 100 + 9;
ll n;
ll a[N];
ll sum, avg;
ll ans = 0;
void Init() {}
// 总体思想是不要重复移动纸牌，且一次移动到位
// 1. if a[i]=avg then continue
// 2. if a[i]>avg, then move some of a[i] to a[i+1]
// 3. if a[i]<avg, then find j than sum(i,j) >= (j-i+1)*avg, and move from j to i
// 4. go to 1
void Move(ll i, ll j, ll sd) {
    // 从右往左移
    auto d2 = a[j] - sd - avg;  // 要保留avg+sd，sd是给后面的
    assert(d2 > 0);
    a[j-1] += d2;
    a[j] -= d2;
    ans += 1;
    foryx(k, i, j-1) {
        assert(a[k] >= avg);
        if (a[k] == avg) continue;
        auto d = a[k] - avg;
        a[k] -= d;
        a[k-1] += d;
        ans += 1;
    }
}
void Solve() {
    std::cin >> n;
    sum = 0;
    for0(i, n) {
        std::cin >> a[i];
        sum += a[i];
    }
    assert(sum % n == 0);
    avg = sum / n;
    for (ll i = 0; i < n;) {
        if (a[i] > avg) {
            assert(i < n-1);  // 后面肯定还有纸牌堆，否则就多出来了
            ans += 1;
            auto d = a[i] - avg;
            a[i] -= d;
            a[i+1] += d;
            i += 1;
            continue;
        }
        if (a[i] == avg) {
            i += 1;
            continue;
        }
        assert(a[i] < avg);
        ll s = a[i];
        for (ll j = i+1; j < n; ++j) {
            s += a[j];
            auto sd = s - (j-i+1)*avg;
            if (sd >= 0) { // 够了
                Move(i, j, sd);
                i = j;  // j这个位置可能还有牌多出来
                break;
            }
        }
    }
    col(ans);
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Init();
    ll t = 1;
    // std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
