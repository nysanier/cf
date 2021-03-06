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
ll n;
std::string a[N];
char res[N][N];
// up/ri/do/le
// ur/dr/dl/ul
const ll dir[8][2] = {
    {0,1}, {1,0}, {0,-1}, {-1,0},
    {1,1}, {1,-1}, {-1,-1}, {-1,1}
};
const std::string s("yizhong");
void Init() {
    memset(res, '*', sizeof(res));
}
bool Check(ll x, ll y, ll d) {
    for0(i, 7) {  // yizhong
        if (i > 0) {
            x += dir[d][0];
            y += dir[d][1];
        }
        if (x<0 || x>=n || y<0 || y>=n || a[x][y]!=s[i])
            return false;
    }
    return true;
}
void Paint(ll x, ll y, ll d) {
    for0(i, 7) {  // yizhong
        if (i > 0) {
            x += dir[d][0];
            y += dir[d][1];
        }
        res[x][y] = s[i];
    }
}
void Solve() {
    std::cin >> n;
    for0(i, n) {
        std::cin >> a[i];
        res[i][n] = 0;
    }
    for0(i, n) for0(j, n) for0(d, 8) {
        if (Check(i, j, d)) {
            Paint(i, j, d);
        }
    }
    for0(i, n) {
        col(res[i]);
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
