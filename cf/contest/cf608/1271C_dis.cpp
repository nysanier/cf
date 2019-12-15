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
using ll = int32_t;
// using ll = int64_t;
using Vec = std::vector<ll>;
using Pair = std::pair<ll, ll>;
using Set = std::set<ll>;
using Map = std::map<ll, ll>;
using Hash = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 2e5 + 9;
const ll INF = 1e9 + 21;
ll n, Sx, Sy;
ll x[N], y[N];
// ll ans[N];
Map x01, y01, x10, y10;
Set setx, sety;
ll ix = 0, iy = 0;
void Solve() {
    std::cin >> n >> Sx >> Sy;
    for0(i, n) {
        std::cin >> x[i] >> y[i];
        x01[x[i]] = 0;
        y01[x[i]] = 0;
    }
    for (auto& kv : x01) {
        kv.second = ix;
        x10[ix] = kv.first;
        ++ix;
    }
    for (auto& kv : y01) {
        kv.second = iy;
        y10[iy] = kv.first;
        ++iy;
    }

    Map mx, my;
    for0(i, n) {
        auto x1 = x01[x[i]];
        auto y1 = y01[y[i]];
        mx[x1]++;
        my[y1]++;
    }
    Map xx, yy;
    for (auto& kv : mx) {
        xx[-kv.second] = kv.first;  // x1
    }
    for (auto& kv : my) {
        yy[-kv.second] = kv.first;  // y1
    }

    if (x10[xx.begin()->second] == Sx && y10[yy.begin()->second] == Sy) {
        
    }

    // output
    // for0(i, n) {
    //     co(a[i]);
    // }
    // col("");
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
