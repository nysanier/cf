#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (decltype(n) i = x; i < (n)+(x); ++i)
#define fornr(i, x, n) for (auto i = (n)-1+(x); i >= x; --i)
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (auto i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (auto i = y; i >= x; i -= d)
#define forxy(i, x, y) forxyd(i, x, y, 1)
#define foryx(i, x, y) foryxd(i, x, y, 1)
#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

// type
using ll = int32_t;
// using ll = int64_t;
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
const ll N = 2e3 + 9;
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
ll n, m;
// ll a[N], b[N];
void Init() {}
void Count(Mp& mp, const Vec& vec) {
    for (auto v : vec) {
        mp[v] += 1;
    }
}
void Solve() {
    std::cin >> n >> m;
    Vec a(n), b(n);
    for0(i, n) {
        std::cin >> a[i];
    }
    for0(i, n) std::cin >> b[i];
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    Mp mpa;
    Count(mpa, a);
    Mp mpb;
    Count(mpb, b);
    ll ans = INF;
    for (auto& kvb : mpb) {
        auto d = kvb.first - mpa.begin()->first;
        Mp mp;
        for (auto& kva : mpa) {
            auto k = (kva.first+d+m) % m;
            mp[k] = kva.second;
        }
        if (mp == mpb) {
            auto res = (d+m)%m;
            if (res < ans) {
                ans = res;
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

#if 0
    Init();
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Init();
    Solve();
#endif

    return 0;
}
