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
#define foryx(i, x, y) for (auto i = y; i >= x; --i)
#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

// type
// using ll = int32_t;
using ll = int64_t;
using Vec = std::vector<ll>;
using Pair = std::pair<ll, ll>;
using Set = std::set<ll>;
using Map = std::map<ll, ll>;
using Hash = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 1e5 + 9;
const ll INF = 1e9 + 21;
ll a, b, c, d, e, f;
// ll ans[N];
void Solve() {
    std::cin >> a >> b >> c >> d >> e >> f;
    auto b1 = std::min(b, c);
    Set set1;
    {
        auto d1 = std::min(a, d);
        auto d2 = std::min(d - d1, b1);
        set1.insert(e * d1 + f * d2);
    }
    {
        auto d2 = std::min(b1, d);
        auto d1 = std::min(d - d2, a);
        set1.insert(e * d1 + f * d2);
    }

    // output
    // for0(i, n) {
    //     co(a[i]);
    // }
    col(*--set1.end());
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
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
