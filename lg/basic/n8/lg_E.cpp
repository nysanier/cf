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

// -------------------------------------------------
struct S{
    ll r,c,v;
};
// 马步
const ll dir[8][2] = {
    {-1, +2}, {+1, +2},  // 右边
    {+2, -1}, {+2, +1},  // 下边
    {-1, -2}, {+1, -2},  // 左边
    {-2, -1}, {-2, +1},  // 上边
};
const ll N = 400 + 9;
ll n, m;
ll a[N][N];
S src;
void Init() {
    memset(a, -1, sizeof(a));
}
void Solve() {
    std::cin >> n >> m;
    std::cin >> src.r >> src.c;
    src.v = 0;
    std::queue<S> q;
    q.push(src);
    a[src.r][src.c] = src.v;
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        auto nv = t.v + 1;
        for0(i, 8) {
            auto nr = t.r + dir[i][0];
            auto nc = t.c + dir[i][1];
            if (nr < 1 || nr >n || nc < 1 || nc > m) continue;
            if (a[nr][nc] != -1) continue;
            a[nr][nc] = nv;
            q.push({nr, nc, nv});
        }
    }
    for1(i, n) {
        for1(j, m) {
            printf("%-5d", a[i][j]);
        }
        puts("");
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
