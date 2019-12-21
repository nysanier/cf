#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (decltype(n) i = x; i < (n)+(x); ++i)
#define fornr(i, x, n) for (auto i = (n)-1+(x); i >= x; --i)
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (auto i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (auto i = y; i >= x; i -= d)
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
const ll N = 3e5 + 9;
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
ll n;
ll a[N];
void Init() {}
void Solve() {
    std::cin >> n;
    ll sum = 0;
    for0(i, n) {
        std::cin >> a[i];
        if (a[i] > 2) {
            auto b = (a[i]-1) / 2;
            a[i] -= b * 2;
            sum += b;
        }
    }

    for (ll i = 0; i < n;) {
        // 2 *
        if (a[i] == 2) {
            sum += 1;
            i += 1;
            continue;
        }

        // 1 *
        assert(a[i] == 1);
        // 1 end
        if (i == n-1) {
            break;
        }
        // 1 ? end
        if (i == n-2) {
            sum += 1;
            break;
        }

        // 1 1 *
        if (a[i+1] == 1) {
            sum += 1;
            i += 2;
            continue;
        }
    
        // ????
        // 1 2 *
        assert(a[i+1] == 2);
        // 1 2 2 *
        if (a[i+2] == 2) {
            sum += 2;
            a[i+2] -= 1;
            i += 2;
            continue;
        }

        // 1 2 1 *
        assert(a[i+2] == 1);
        sum += 1;
        i += 2;
    }

    col(sum);
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

#if 0
    Init();
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Init();
    Solve();
#endif

    return 0;
}
