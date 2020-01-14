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

// 回溯?
// -------------------------------------------------
const ll N = 20 + 9;
ll n;
std::string a[N];
std::string head;
ll vis[N];  // 最多两次
ll ans = 0;
std::string res;
void Init() {
    memset(vis, 0, sizeof(vis));
}
// 判断t是否可以接在s后面，如果可以，接上去的那段是v
bool Check(const std::string& s, const std::string& t, std::string& v) {
    if (s.size() == 1 || t.size() == 1) return false;
    ll m1 = std::min(s.size()-1, t.size()-1);
    for (ll i = 1; i <= m1; ++i) {
        auto p1 = s.rfind(t.substr(0, i));
        if (p1 == s.size() - i) {
            v = t.substr(i);
            return true;
        }
    }
    return false;
}
void Dfs(const std::string& cur) {
    // static ll cnt = 0;
    // if (cnt++ < 100) DUMP(cur, res);
    for (int i = 0; i < n; ++i) {
        if (vis[i] >= 2) continue;
        std::string v;
        if (!Check(cur, a[i], v)) continue;
        res.append(v);
        if (res.size() > ans) {
            ans = res.size();
            // DUMP(ans, res);
        }
        vis[i] += 1;
        Dfs(a[i]);
        vis[i] -= 1;
        res.resize(res.size() - v.size());
    }
}
void Solve() {
    std::cin >> n;
    for0(i, n) {
        std::cin >> a[i];
    }
    std::cin >> head;
    for0(i, n) {
        if (a[i].size() > 1 && a[i][0] == head[0]) {
            vis[i] += 1;
            res.append(a[i]);
            if (res.size() > ans)
                ans = res.size();
            Dfs(a[i]);
            res.resize(res.size() - a[i].size());
            vis[i] -= 1;
        }
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

    Init();
    ll t = 1;
    // std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
