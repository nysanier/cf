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

/*
解体思路：0->1 && 1->0，所以对于这个连通分量中的所有格子可以互相到达，且能够到达到的格子数也相同
    1. 计算所有连通分量，同时计算这个分量大小
    2. 对于每个mi，判断在哪个连通分量中，输出对应的分量大小
    3. 
*/
// -------------------------------------------------
// up/right/down/left
const ll dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
const ll N = 1000 + 9;
ll n, m;
std::string a[N];
ll vis[N][N];
ll res[N][N];
ll cnt;  // 当前连通分量计数
std::vector<Pr> vec;  // 当前连通分量包含了哪些点
// std::;  // i*1000+j作为标记
void Init() {
    memset(vis, 0, sizeof(vis));
}
// v: 当前值，0: 那么下一次必须是1
void Dfs(ll r, ll c, ll v) {
    for0(d, 4) {
        auto nr = r + dir[d][0];
        auto nc = c + dir[d][1];
        auto nv = !v;
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (vis[nr][nc] || a[nr][nc]-'0' != nv) continue;
        vis[nr][nc] = 1;
        vec.push_back({nr, nc});
        cnt += 1;
        Dfs(nr, nc, nv);
    }
}
void Solve() {
    std::cin >> n >> m;
    for0(i, n) {
        std::cin >> a[i];
    }
    for0(i, n) for0(j, n) {
        if (!vis[i][j]) {
            vis[i][j] = 1;
            vec.clear();
            vec.push_back({i,j});
            cnt = 1;
            Dfs(i, j, a[i][j]-'0');
            for (auto& kv : vec) {
                res[kv.first][kv.second] = cnt;
            }
        }
    }
    ll r, c;
    for0(i, m) {
        std::cin >> r >> c;
        col(res[r-1][c-1]);
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
