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
const ll N = 1e6 + 9;
const ll INF = 1e9 + 21;
ll n;
// ll ans[N];
Map map1;
void Init() {
    forxy(i, 1, 9) {  // 1,2,3
        int v = 0;
        forxy(j, 1, 9) {
            v = 10 * v + i;  // 1,11,111
            map1[v] = 0;
        }
    }
    // DUMP(map1);

    int sum = 1;
    for (auto& kv : map1) {
        kv.second = sum++;
    }
    // DUMP(map1);
}
void Solve() {
    std::cin >> n;
    // if (n == 1e9) {
    //     col(map1.size());
    //     return;
    // }

    auto it = map1.upper_bound(n);
    // DUMP(n, it->first, it->second);
    if (it == map1.end()) {
        col(map1.size());
        return;
    }

    col(it->second - 1);
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

#if 1
    Init();
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
