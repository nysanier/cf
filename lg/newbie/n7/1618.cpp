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
const ll N = 10;
ll a, b, c;
// ll f[N];
bool vis[N];
ll s[N];
std::set<std::string> st;
void Init() {
    // for1(i, 9) f[i] = i;
    std::fill(vis, vis+N, false);
}
void Check() {
    auto x = 100*s[1] + 10*s[2] + s[3];
    auto y = 100*s[4] + 10*s[5] + s[6];
    auto z = 100*s[7] + 10*s[8] + s[9];
    if (x*b==y*a && y*c==z*b && x*c==z*a) {
        auto str = std::to_string(x) + " " + std::to_string(y) + " " + std::to_string(z);
        st.insert(str);
    }
}
void Dfs(ll d) {
    if (d == 10) {
        Check();
        return;
    }
    for1(i, 9) {
        if (!vis[i]) {
            vis[i] = true;
            s[d] = i;
            Dfs(d+1);
            vis[i] = false;
        }
    }
}
void Solve() {
    std::cin >> a >> b >>c;
    Dfs(1);
    if (st.empty()) {
        col("No!!!");
    } else {
        for (auto& str : st) {
            col(str);
        }
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

    Init();
    ll t = 1;
    // std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
