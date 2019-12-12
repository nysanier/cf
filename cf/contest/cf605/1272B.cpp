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
const ll N = 1e5 + 9;
const ll INF = 1e9 + 21;
ll n;
std::string s;
// ll ans[N];
ll c[256];
void Solve() {
    std::cin >> s;
    c['L'] = c['R'] = c['D'] = c['U'] = 0;
    for0(i, s.size()) {
        c[s[i]] += 1;
    }
    auto lr = std::min(c['L'], c['R']);
    auto ud = std::min(c['D'], c['U']);
    if (lr == 0 && ud == 0) {
        std::cout << 0 << std::endl;
        return;
    }
    if (lr == 0) {
        std::cout << 2 << std::endl;
        std::cout << "UD" << std::endl;
        return;
    }
    if (ud == 0) {
        std::cout << 2 << std::endl;
        std::cout << "LR" << std::endl;
        return;
    }
    auto ans = (lr + ud) * 2;
    std::cout << ans << std::endl;
    for0(i, lr) std::cout << "L";
    for0(i, ud) std::cout << "U";
    for0(i, lr) std::cout << "R";
    for0(i, ud) std::cout << "D";
    // output
    // for0(i, n) {
    //     std::cout << ans[i] << " ";
    // }
    std::cout << "" << std::endl;
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
