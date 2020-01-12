#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (long i = x; i < n+x; ++i)
#define fornr(i, x, n) for (long i = n-1+x; i >= x; --i)  // must be signed, or 0->~0
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (long i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (long i = y; i >= x; i -= d)
#define forxy(i, x, y) forxyd(i, x, y, 1)
#define foryx(i, x, y) foryxd(i, x, y, 1)
#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

// type
// using ll = int32_t;
using ll = int64_t;
using Vec = std::vector<ll>;
using Deq = std::deque<ll>;
using Lst = std::list<ll>;
using Pr = std::pair<ll, ll>;
using St = std::set<ll>;
using Mst = std::multiset<ll>;
using Ust = std::unordered_set<ll>;
using Mp = std::map<ll, ll>;
using Mmp = std::multimap<ll, ll>;
using Ump = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 100 + 9;
std::string a, b, c;
Mp mp;  // secret -> plain
St st;  // all used plain char
void Init() {}
void Solve() {
    std::cin >> a >> b >> c;
    if (a.size() != b.size()) {  // 不等长
        col("Failed");
        return;
    }

    for0(i, a.size()) {
        auto x = a[i];
        auto y = b[i];
        auto it = mp.find(x);
        if (it == mp.end()) {
            if (st.find(y) != st.end()) {  // 明文已经被用掉了
                col("Failed");
                return;
            }
            mp[x] = y;
            st.insert(y);
            continue;
        }
        if (it->second != y) {  // 必须唯一映射
            col("Failed");
            return;
        }
    }

    if (mp.size() != 26 || st.size() != 26) {  // 没有映射全
        col("Failed");
        return;
    }

    std::string ans;
    for (auto ch : c)
        ans.push_back(mp[ch]);
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

    Init();
    ll t = 1;
    // std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
