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
void Init() {}
bool Check(ll a[3]) {
    St st;
    for0(i, 3) {
        auto v3 = a[i] / 100;
        if (v3 < 1 || v3 > 9) return false;
        st.insert(v3);
        auto v2 = (a[i]-v3*100) / 10;
        st.insert(v2);
        auto v1 = a[i] - v3*100 - v2*10;
        st.insert(v1);
    }
    return st.size() == 9 && *st.begin()==1 && *--st.end()==9;
}
void Solve() {
    for1(i, 9) {
        for1(j, 9) {
            if (j == i) continue;
            for1(k, 9) {
                if (k == j || k == i) continue;
                ll a[3];
                a[0] = 100*i +10*j + k;
                a[1] = a[0] * 2;
                a[2] = a[0] * 3;
                if (Check(a)) {
                    co(a[0]); co(a[1]); col(a[2]);
                }
            }
        }
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
