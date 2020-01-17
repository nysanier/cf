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
解题思路:
    1. bfs，最快搜索到的就是最少时间。这里机器人会占据4个格子，因此需要注意计算障碍物对机器人的影响(只能在1~n-1范围内活动)
    2. 左上角坐标表示这个格子
    3. 
解题步骤:
    1. bfs搜索
    2. 
    3. 
典型测试数据:
4 4
0 0 0 0
0 0 0 0
0 0 1 0
0 0 0 0
3 1 1 3 W
*/
// -------------------------------------------------
struct S {
    ll r, c;  // 当前位置
    ll d;  // 当前方向
    ll v;  // 当前步数
};
std::map<std::string, ll> mp{
    {"E", 0},   // right
    {"S", 1},   // down
    {"W", 2},   // left
    {"N", 3}    // up
};
Mp toLeft{
    {0, 3},
    {3, 2},
    {2, 1},
    {1, 0},
};
Mp toRight{
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 0},
};
// right(E,0)/down(S,1)/left(W,2)/up(N,3)
const ll dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
const ll N = 50 + 9;
ll n, m;
ll a[N][N];
ll vis[N][N][4];
S last[N][N][4];
S src, dst;
void Init() {
    memset(vis, 0, sizeof(vis));
}
// 判断这个格点相邻的四个格子是否不是障碍物
// 机器人肯定在房间内，因此nr/nc的值在[0,n)之间
bool Check(ll r, ll c) {
    if (r <= 0 || r >= n || c <= 0 || c >= m) return false;
    auto nr = r - 1;
    auto nc = c - 1;
    if (a[r][c]) return false;
    if (a[r][nc]) return false;
    if (a[nr][c]) return false;
    if (a[nr][nc]) return false;
    return true;
}
bool Next(ll x, const S& s, ll& nr, ll& nc, ll& nd) {
    if (x == 0) {
        // 向右转（Right）
        nr = s.r;
        nc = s.c;
        nd = toRight[s.d];
        return true;
    }

    if (x == 1) {
        // 向左转（Left）
        nr = s.r;
        nc = s.c;
        nd = toLeft[s.d];
        return true;
    }

    // 优先3步，然后2步，最后1步
    if (x == 2) {
        // 向前移动3步（Run）
        nr = s.r;
        nc = s.c;
        nd = s.d;
        for0(i, 3) {
            nr += dir[s.d][0];
            nc += dir[s.d][1];
            if (!Check(nr, nc))
                return false;
        }
        return true;
    }

    if (x == 3) {
        // 向前移动2步（Walk）
        nr = s.r;
        nc = s.c;
        nd = s.d;
        for0(i, 2) {
            nr += dir[s.d][0];
            nc += dir[s.d][1];
            if (!Check(nr, nc))
                return false;
        }
        return true;
    }

    if (x == 4) {
        // 向前移动1步（Creep）
        nr = s.r;
        nc = s.c;
        nd = s.d;
        for0(i, 1) {
            nr += dir[s.d][0];
            nc += dir[s.d][1];
            if (!Check(nr, nc))
                return false;
        }
        return true;
    }

    assert(0);
    return false;
}
void Bfs() {
    std::queue<S> q;
    vis[src.r][src.c][src.d] = 1;
    // last[src.r][src.c][src.d] = {-1,};  // r<0
    q.push(src);
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        if (t.r == dst.r && t.c == dst.c) {
            dst.d = t.d;  // 最后到达时候的方向
            col(t.v);
            return;
        }
        auto nv = t.v + 1;
        ll nr, nc, nd;
        // DUMP(t.v, t.r, t.c, t.d);
        for0(i, 5) {
            if (!Next(i, t, nr, nc, nd)) continue;
            if (vis[nr][nc][nd]) continue;
            // DUMP("vis", i, nr, nc, nd, nv);
            vis[nr][nc][nd] = 1;
            // last[nr][nc][nd] = t;
            q.push({nr,nc,nd,nv});
        }

    }
    col(-1);
}
void Solve() {
    std::cin >> n >> m;
    for0(i, n) for0(j, m) {
        std::cin >> a[i][j];
    }
    std::cin >> src.r >> src.c;
    std::cin >> dst.r >> dst.c;
    {
        std::string str;
        std::cin >> str;
        src.d = mp[str];
        src.v = 0;
        dst.d = -1;
    }
    Bfs();

    // 查看路径
    // if (dst.d < 0) return;
    // ll r = dst.r, c = dst.c, d = dst.d;
    // DUMP(r, c, d);
    // ll cnt = 10;
    // while (r >= 0 && cnt-- > 0) {
    //     DUMP(r, c, d);
    //     r = last[r][c][d].r;
    //     c = last[r][c][d].c;
    //     d = last[r][c][d].d;
    // }
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
