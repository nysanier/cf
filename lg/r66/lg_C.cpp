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
const ll N = 5e2 + 9;
const ll M = 2e2 + 9;
const ll MOD = 998244353;
ll n, m, k;
bool mk[N][N];
ll rs[M][N];
void Init() {
    for0(i, N)
        std::fill(mk[i], mk[i]+N, false);
    for0(i, M)
        std::fill(rs[i], rs[i]+N, 0);
}
void Sub1() {
    ll a = 1;
    ll b = 0;
    for1(p, m) {
        auto a2 = (b * (n-1)) % MOD;
        auto b2 = (b * (n-2) + a) % MOD;
        a = a2;
        b = b2;
    }
    col(a);
}
void Solve() {
    std::cin >> n >> m >> k;
    if (k == 0) {
        Sub1();
        return;
    }

    ll a, b;
    for0(i, k) {
        std::cin >> a >> b;
        mk[a][b] = true;
    }
    for1(i, n) {
        mk[i][i] = true;
    }

    // 0:
    rs[0][1] = 1;
    // 1: i(1) -> j
    for1(j, n) {
        if (!mk[1][j]) {
            rs[1][j] += rs[0][1];
        }
    }
    // 2e2 * 5e2 * 5e2 = 5e7 ok!
    // i(p-1) -> j(p)
    forxy(p, 2, m) {
        for1(i, n) {
            for1(j, n) {
                if (!mk[i][j])
                    rs[p][j] = (rs[p][j] + rs[p-1][i]) % MOD;
            }
        }
    }

    col(rs[m][1]);
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
