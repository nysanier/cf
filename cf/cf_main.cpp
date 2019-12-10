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
using Int = int32_t;
// using Int = int64_t;
using Vec = std::vector<Int>;
using Pair = std::pair<Int, Int>;
using Set = std::set<Int>;
using Map = std::map<Int, Int>;
using Hash = std::unordered_map<Int, Int>;

// -------------------------------------------------
const Int N = 1e6 + 9;
const Int INF = 1e9 + 21;
Int n;
Int a[N];
void Solve() {
    std::cin >> n;
    for0(i, n) {
        std::cin >> a[i];
    }
    // output
    // for0(i, n) {
    //     std::cout << a[i] << " ";
    // }
    // std::cout << "" << std::endl;
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);

#if 0
    Int t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
