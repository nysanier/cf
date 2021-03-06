#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include <dump.h>
#else
# define DUMP(args...)
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
using Pair = std::pair<ll, ll>;
using Set = std::set<ll>;
using Map = std::map<ll, ll>;
using Umap = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 2e5 + 9;
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
ll n;
ll a[N];
ll b[N];
void Init() {}
void Solve() {
    std::cin >> n;
    for1(i, 2 * n) {
        std::cin >> a[i];
    }
    b[0] = 0;
    for1(i, n) {
        if (a[i] == 1) {
            b[i] = b[i-1] + 1;
        } else {
            b[i] = b[i-1] - 1;
        }
    }
    // Vec vec1(b,b+n+1);
    std::multimap<ll, ll> mapx;  // value, position
    mapx.insert({0, 2*n+1});
    b[2*n+1] = 0;
    foryx(i, n+1, 2*n) {
        if (a[i] == 2) {
            b[i] = b[i+1] + 1;
        } else {
            b[i] = b[i+1] - 1;
        }
        // setx.insert({b[i],i});
        mapx.insert({b[i],i});
    }
    // Vec vec2(b+n+1,b+2*n+2);
    // DUMP(vec1, vec2);

    ll ans = INF;
    for0r(i, n+1) {
        auto it = mapx.lower_bound(b[i]);
        if (it == mapx.end()) continue;
        if (it->first != b[i]) continue;
        auto v = it->second;
        auto it2 = mapx.upper_bound(b[i]);
        while (it != it2) {
            if (it->second < v) v = it->second;
            ++it;
        }
        // DUMP(i,v);
        auto res = v-i-1;
        if (res < ans) ans = res;
        continue;
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

#if 1
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
