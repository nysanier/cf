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
using ll = int;
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

// 找到所有的0的连通分量，并标记这个每个连通分量是否最后能够触碰到边界
// 如果不能触碰到边界，那么就是被1围堵了
// -------------------------------------------------
const ll N = 30 + 9;
// up/right/down/left
const ll dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
ll n;
ll a[N][N];
ll vis[N][N];
std::vector<std::set<Pr>> x;  // 所有的连通分量
std::vector<bool> y;
void Init() {
    memset(vis, 0, sizeof(vis));
}
void Bfs(ll r, ll c) {
    bool flag = false;  // 能否碰到边界
    std::vector<Pr> vec;  // 当前连通分量
    vec.push_back({r,c});
    std::queue<Pr> q;
    q.push({r,c});
    DUMP(r, c);
    vis[r][c] = 1;
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        for0(d, 4) {
            auto nr = t.first + dir[d][0];
            auto nc = t.second + dir[d][1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                flag = true;
                continue;
            }
            if (a[nr][nc] != 0 || vis[nr][nc]) continue;
            vis[nr][nc] = 1;
            q.push({nr,nc});
            static ll cnt = 0;
            if (cnt++ < 100)
                DUMP(nr, nc);
            vec.push_back({nr,nc});
        }
    }
    
    if (!flag) {
        for(auto& kv : vec) {
            a[kv.first][kv.second] = 2;
        }
    }
}
void Solve() {
    std::cin >> n;
    for0(i, n) for0(j, n)
        std::cin >> a[i][j];
    for0(i, n) for0(j, n) {
        if (a[i][j] == 0 && !vis[i][j]) {
            Bfs(i, j);
        }
    }
    for0(i, n) for0(j, n) {
        printf("%d%c", a[i][j], j==n-1 ? '\n' : ' ');
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
