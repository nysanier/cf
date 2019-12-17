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
using Umap = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 1e6 + 9;
const ll INF = 1e9 + 21;
std::string s, c;
void Init() {}
void Solve() {
    std::cin >> s >> c;
    // AB, AB
    if (s == c) {
        col("---");
        return;
    }

    // AB, ABC
    if (s < c) {
        col(s);
        return;
    }

    ll i = 0, j = 0;
    while (i < s.size() && j < c.size() && s[i] == c[j]) {
        ++i;
        ++j;
    }

    assert(i < s.size());

    if (j == c.size()) {
        assert(i > 0);
        --i;
        --j;
    }
    forxy(x, i+1, s.size()-1) {
        std::swap(s[i], s[x]);
        if (s < c) {
            col(s);
            return;
        }
        std::swap(s[i], s[x]);
    }

    col("---");
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
