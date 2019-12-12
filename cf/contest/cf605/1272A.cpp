#include <bits/stdc++.h>
#include <bits/extc++.h>

// abbr
#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)
#define PB push_back
#define FI first
#define SE second

// type
using ll = int32_t;
// using ll = int64_t;
using Vec = std::vector<ll>;
using Pair = std::pair<ll, ll>;
using Set = std::set<ll>;
using Map = std::map<ll, ll>;
using Hash = std::unordered_map<ll, ll>;

// -------------------------------------------------
// const ll N = 1e6 + 9;
// const ll INF = 1e9 + 21;
// ll a, b, c;
// ll a[N];
// ll ans[N];
ll a[3], b[3], c[3];
void Solve() {
    std::cin >> a[1] >> b[1] >> c[1];
    // for0(i, n) {
    //     std::cin >> a[i];
    // }
    a[0] = a[1] - 1; a[2] = a[1] + 1;
    b[0] = b[1] - 1; b[2] = b[1] + 1;
    c[0] = c[1] - 1; c[2] = c[1] + 1;
    Set ans;
    for0(i, 3) {
        for0(j, 3) {
            for0(k, 3) {
                ll v = std::abs(a[i]-b[j]) + std::abs(a[i]-c[k]) + std::abs(b[j]-c[k]);
                ans.insert(v);
            }
        }
    }
    // output
    // for0(i, n) {
    //     std::cout << ans[i] << " ";
    // }
    std::cout << *ans.begin() << std::endl;
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#if 1
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
