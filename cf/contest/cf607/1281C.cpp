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
using Umap = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 1e6 + 9;
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
ll x;
std::string s;
void Init() {}
void Solve() {
    s.reserve(N);
    std::cin >> x >> s;
    ll ans = s.size();
    // DUMP(s, x, ans);
    for0(i, x) {
        auto d = s[i] - '0';  // 1~3
        if (s.size() < x) {
            auto p1 = i+1;
            size_t l1 = s.size()-p1;
            for0(j, d-1) {
                size_t r = x - s.size();  // >= 0
                auto r2 = std::min(r, l1);
                s.append(s.begin()+p1, s.begin()+p1+r2);
            }
            // DUMP(s2, s);
        }
        ans = (i+1 + (ans-i-1+MOD) * d) % MOD;  // 为什么要 +MOD ？
        // DUMP(ans);
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
