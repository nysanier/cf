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
const ll N = 2e5 + 9;
const ll INF = 1e9 + 21;
ll n, c;
ll a[N], b[N];
ll f[N][2];  // 0:不在电梯,1:在电梯
// dp的关键是设计出状态转移方程, 比如这题在/不在电梯就是两种状态!!!
// 这个题目有点歧义, 就是从电梯走出到走楼梯的话就不用等开门吗?
void Solve() {
    std::cin >> n >> c;
    for1(i, n-1) {
        std::cin >> a[i];
    }
    for1(i, n-1) std::cin >> b[i];

    f[0][0] = 0;
    f[0][1] = c;
    for1(i, n-1) {
        auto m01 = f[i-1][0] + a[i];
        auto m02 = f[i-1][1] + a[i];  // no need walt out from elevator?
        f[i][0] = std::min(m01, m02);

        // 为什么这段可以省略掉?
        auto m03 = f[i-1][0] + b[i] + c;  // 为什么不能走电梯上来?
        auto m04 = f[i-1][1] + b[i];  // 为什么不能走电梯上来?
        auto m0 = std::min(m03, m04);
        f[i][0] = std::min(f[i][0], m0);
        
        auto m11 = f[i-1][0] + b[i] + c;
        auto m12 = f[i-1][1] + b[i];
        f[i][1] = std::min(m11, m12);

        // 为什么这段可以省略掉?
        auto m13 = f[i-1][0] + a[i] + c;  // 走上来,再进电梯
        auto m14 = f[i-1][1] + a[i] + c; // 走出来,再走上来,再走进电梯
        auto m1 = std::min(m13, m14);
        f[i][1] = std::min(f[i][1], m1);
    }
    // output
    for0(i, n) {
        std::cout << std::min(f[i][0], f[i][1]) << " ";
    }
    std::cout << "" << std::endl;
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#if 0
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
