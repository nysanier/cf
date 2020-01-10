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
const ll N = 20 + 9;
struct S {
    ll r, c;
    ll v;
    bool operator<(const S& rhs) const {
        return v > rhs.v;
    }
};
ll m, n, k;
ll a[N][N];
Pr b[N*N];  // 摘到的个数，以及摘完这个回到路边的后k的余值
// 找到最有一个k大于0的只就行，或者反着找到第一个k>=0的只就好
void Init() {}
void Solve() {
    std::cin >> m >> n >> k;
    std::vector<S> vec;
    for1(i, m) for1(j, n) {
        std::cin >> a[i][j];
        if (a[i][j] > 0)
            vec.push_back({i,j,a[i][j]});
    }
    if (vec.empty()) {
        col(0);
        return;
    }
    std::sort(vec.begin(), vec.end());
    DUMP(m, n, k);
    ll lr = 0;
    ll lc = vec[0].c;
    ll lv = 0;
    // DUMP(lr, lc, k);
    for (ll i = 0; i < vec.size(); ++i) {
        auto d = abs(vec[i].r - lr) + abs(vec[i].c - lc);
        b[i].first = vec[i].v + lv;
        b[i].second = k - d - 1 - vec[i].r;  // 去/摘/回
        k -= d + 1;
        lr = vec[i].r;
        lc = vec[i].c;
        lv += vec[i].v;
        // DUMP(i, d, lr, lc, k, ans);
    }
    ll ans = 0;  // 可能一个都摘不到，那么默认是0
    for0r(i, vec.size()) {
        if (b[i].second >= 0) {
            ans = b[i].first;
            break;
        }
    }
    col(ans);
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
