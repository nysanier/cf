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
const int N = 1e4 + 9;
St st;
// abc(x) -> abcba, abccba
void Pd(ll x, ll& r1, ll& r2) {
    r1 = x;
    r2 = x;
    r2 = 10*r2 + x%10;
    x /= 10;  // drop the last digit
    while (x > 0) {
        auto m = x % 10;
        r1 = 10*r1 + m;
        r2 = 10*r2 + m;
        x /= 10;
    }
}
bool Prime(ll x) {
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    // DUMP("prime", x);
    return true;
}
void Init() {
    ll f, g;
    for (ll i = 1; i < N; ++i) {
        Pd(i, f, g);
        if (Prime(f)) st.insert(f);
        if (Prime(g)) st.insert(g);
    }
}
void Solve() {
    ll a, b;
    std::cin >> a >> b;
    auto it1 = st.lower_bound(a);
    auto it2 = st.upper_bound(b);
    for (auto it = it1; it != it2; ++it) {
        col(*it);
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
