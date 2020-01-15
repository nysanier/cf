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
const ll N = 5 + 9;
ll n, m, t;
ll sx, sy, fx, fy;
ll a[N][N];
ll vis[N][N];
ll ans = 0;
// up/right/down/left
const ll dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
void Init() {
    memset(a, 0, sizeof(a));
    memset(vis, 0, sizeof(vis));
}
void Dfs(ll x, ll y) {
    if (x==fx && y==fy) {
        ans += 1;
        return;
    }
    for0(d, 4) {
        auto nx = x + dir[d][0];
        auto ny = y + dir[d][1];
        if (nx<1 || nx>n || ny<1 || ny>m || a[nx][ny] || vis[nx][ny])
            continue;
        vis[nx][ny] = 1;
        Dfs(nx, ny);
        vis[nx][ny] = 0;
    }
}
void Solve() {
    std::cin >> n >> m >> t;
    std::cin >> sx >> sy >> fx >> fy;
    ll x, y;
    for0(i, t) {
        std::cin >> x >> y;
        a[x][y] = 1;  // 障碍
    }
    vis[sx][sy] = 1;
    Dfs(sx, sy);
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
