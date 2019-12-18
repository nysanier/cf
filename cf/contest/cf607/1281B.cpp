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
void Init() {
    // find_last_of/rfind的第2个参数要注意
    {
        std::string t = "a505152535";
        ll p1 = t.size()-1;
        p1 = 3;
        for (;;) {
            // rfind也是这个逻辑！！！
            auto p2 = t.find_last_of('5', p1);  // 忽略p1之后的'5'，而不是从p1开始往后找!!
            if (p2 == 0) {
                DUMP(p2);
                break;
            }
            if (p2 == t.npos) {
                break;
            }
            p1 = p2 - 1;
            DUMP(p2, p1);
        }
    }
}
void Solve() {
    std::cin >> s >> c;
    if (s < c) {
        col(s);
        return;
    }
    auto s2 = s;
    std::sort(s2.begin(), s2.end());
    ll i = 0;
    while (i < s.size() && s[i] == s2[i]) ++i;
    DUMP(s, s2, i);
    if (i == s.size()) {
        if (s < c) {
            col(s);
        } else {
            col("---");
        }
        return;
    }

    auto ch = s2[i];
    auto p1 = i + 1;
    // auto p2 = s.find_last_of(ch, p1);  // 不能用第二参数，否则就是从p1(含)往前找
    auto p2 = s.find_last_of(ch);
    DUMP(ch, i, s[i], p1, p2, s[p2]);
    std::swap(s[i], s[p2]);
    if (s < c) {
        col(s);
    } else {
        col("---");
    }

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
