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
// 可以暴力出来？
const ll N = 2e5 + 9;
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
ll n, p, k;
ll a[N];
ll b[N];
void Init() {}
// buy alone
ll Cal1(ll x, ll px) {
    if (px >= b[x]) {
        px -= b[x];
        return x;
    }
    assert(px >= b[0]);

    ll l = 0;  // >= px
    ll r = x;  // < px
    while (l < r) {
        ll h = (l+r)/2;
        if (px >= b[h]) {
            l = h + 1;
        } else {
            r = h;
        }
    }
    px -= b[l-1];
    return l-1;
}
// with bonus
ll Cal2(ll x, ll& px) {
    ll r = 0;
    forxyd(i, x+k, n, k) {
        if (px >= a[i]) {
            px -= a[i];
            r += k;
        }
    }
    return r;
}
void Solve() {
    std::cin >> n >> p >> k;
    for1(i, n) {
        std::cin >> a[i];
    }
    std::sort(a+1, a+1+n);
    b[0] = 0;
    for1(i, k-1) {
        b[i] = b[i-1] + a[i];
    }

    DUMP(Vec(b,b+k));
    ll ans = 0;
    for0(i, k) {
        DUMP("---", i);
        auto px = p;
        auto r = Cal2(i, px);
        DUMP(px, r);
        r += Cal1(i, px);
        DUMP(r, px);
        ans = std::max(ans, r);
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

#if 1
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
