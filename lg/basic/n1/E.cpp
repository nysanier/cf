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
const ll N = 200 + 9;
ll n, na, nb;
ll a[N], b[N];
void Init() {}
void Solve() {
    std::cin >> n >> na >> nb;
    for0(i, na) std::cin >> a[i];
    for0(i, nb) std::cin >> b[i];
    ll cx = 0, cy = 0;
    for0(i, n) {
        auto x = a[i % na];
        auto y = b[i % nb];
        if (x == 0) {
            if (y==1 || y==4) cy += 1;  // lost
            else if (y==2 || y==3) cx += 1;  // win
        } else if (x == 1) {
            if (y==2 || y==4) cy += 1;
            else if (y==0 || y==3) cx += 1;
        } else if (x == 2) {
            if (y==0 || y==3) cy += 1;
            else if (y==1 || y==4) cx += 1;
        } else if (x == 3) {
            if (y==0 || y==1) cy += 1;
            else if (y==2 || y==4) cx += 1;
        } else if (x == 4) {
            if (y==2 || y==3) cy += 1;
            else if (y==0 || y==1) cx += 1;
        }
    }
    co(cx); col(cy);
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
