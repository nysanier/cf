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
const ll N = 1e6 + 9;
ll n;
ll a[N], s[N], t[N];
void Init() {}
void Solve() {
    std::cin >> n;
    for0(i, n) {
        std::cin >> s[i] >> t[i];
        a[i] = i;
    }
    std::sort(a, a+n, [](int x, int y){
        return s[x] < s[y];
    });
    ll ans = 0;
    // ll cur = 0;  // 当前结束点
    ll x = -1;  // 待确认的线段
    for0(i, n) {
        if (x == -1) {
            x = a[i];
            continue;
        }
        auto y = a[i];
        // 前面那根可以确认了
        if (s[y] >= t[x]) {
            ans += 1;
            x = y;
            continue;
        }
        // 这根线段没有替换优势，直接放弃
        if (t[y] >= t[x]) {
            continue;
        }
        assert(t[y] < t[x]);
        // 直接替换
        x = y;
    }
    if (x != -1) {
        ans += 1;
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
