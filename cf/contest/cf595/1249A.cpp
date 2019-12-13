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

// type
using ll = int32_t;
// using ll = int64_t;
using Vec = std::vector<ll>;
using Pair = std::pair<ll, ll>;
using Set = std::set<ll>;
using Map = std::map<ll, ll>;
using Hash = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 1e2 + 9;
const ll INF = 1e9 + 21;
ll n;
ll a[N];
void Solve() {
    std::cin >> n;
    for0(i, n) {
        std::cin >> a[i];
    }
    std::sort(a, a+n);
    bool flag = false;
    for1(i, n-1) {
        if (a[i] == a[i-1]+1) {
            flag = true;
            break;
        }
    }
    for0(i, n) {
        DUMP(i, n, a[i]);
    }
    if (flag)
        std::cout << 2 << std::endl;
    else
        std::cout << 1 << std::endl;
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
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
