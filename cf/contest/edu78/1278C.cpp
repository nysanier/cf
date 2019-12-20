#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include <dump.h>
#else
# define DUMP(args...)
#endif

// abbr
#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, y, x) for (auto i = y; i >= x; --i)
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
    foryx(i, 2*n, n+1) {
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
