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
using ll = long long;
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
const ll N = 20 + 9;
ll a, b, c;
ll f[N][N][N];
ll vis[N][N][N];
void Init() {
    memset(vis, 0, sizeof(vis));
}
ll w(ll a, ll b, ll c) {
    if (a<=0 || b<=0 || c<=0) return 1;  // > 1
    if (a>20 || b>20 || c>20) return w(20, 20, 20);  // <= 20
    if (vis[a][b][c]) return f[a][b][c];
    ll r;
    if (a<b && b<c) r = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    else r = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
    f[a][b][c] = r;
    vis[a][b][c] = 1;
    return r;
}
void Solve() {
    for (;;) {
        std::cin >> a >> b >> c;
        if (a==-1 && b==-1 && c==-1) break;
        auto ans = w(a, b, c);
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);
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
