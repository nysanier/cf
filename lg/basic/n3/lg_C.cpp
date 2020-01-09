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
const ll N = 5e3 + 9;
ll n, m;
ll a[N];
Pr pr[N];
void Init() {}
void Solve() {
    std::cin >> n >> m;
    ll seq, score;
    for0(i, n) {
        std::cin >> seq >> score;
        a[i] = -score;  // 方便逆向排序
        pr[i] = {a[i], seq};  // 优先按成绩降序，再按序号生序
    }
    std::sort(a, a+n);
    auto m2 = (ll)std::floor(m * 1.5);
    auto cj = a[m2-1];
    auto m3 = m2;  // 最终的人数
    for (ll i = m2; i < n; ++i) {
        if (a[i] > a[i-1]) break;
        m3 += 1;
    }
    std::sort(pr, pr+n);  // 其实只要一遍排序就够了，不需要a[i]
    co(-cj); col(m3);
    for0(i, m3) {
        co(pr[i].second); col(-pr[i].first);
    }
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
