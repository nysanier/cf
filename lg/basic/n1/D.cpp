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
const ll N = 1000 + 9;
ll m, n, k, l, d;
void Init() {}
void Ans(ll tot, ll num, Mp& mp) {
    DUMP(tot, num, mp);
    Mmp cnt;
    for (auto& kv : mp) {
        cnt.insert({-kv.second, kv.first});
    }
    DUMP(cnt);
    St st;
    ll i = 0;
    for (auto it = cnt.begin(); it != cnt.end() && i < num; ++it, ++i)
        st.insert(it->second);
    DUMP(st);
    // 为什么不说明, k/l肯定比哪些学生少?
    for1(j, tot) {
        if (st.size() == num) break;
        st.insert(j);
    }
    DUMP(st);

    if (st.empty()) {
        puts("");
        return;
    }
    auto it = st.begin();
    printf("%d", *it);
    for (++it; it != st.end(); ++it) {
        printf(" %d", *it);
    }
    puts("");
}
void Solve() {
    std::cin >> m >> n >> k >> l >> d;
    DUMP(m, n, k, l, d);
    Mp row, col;
    ll x, y, p, q;
    for0(i, d) {
        std::cin >> x >> y >> p >> q;
        assert(x==p || y==q);
        if (x == p) {  // col
            if (y > q) std::swap(y, q);
            col[y] += 1;
            continue;
        }
        // row
        if (x > p) std::swap(x, p);
        row[x] += 1;
    }
    DUMP(row, col);
    Ans(m, k, row);
    Ans(n, l, col);
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
