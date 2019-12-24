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
void Solve1() {
    std::cin >> n >> p >> k;
    for0(i, n) {
        std::cin >> a[i];
    }
    std::sort(a, a+n);
    ll r1 = 0, p1 = p;
    if (a[0] <= p1) {
        r1 += 1;
        p1 -= a[0];
    }
    forxyd(i, 2, n-1, 2) {
        if (p1 >= a[i]) {
            p1 -= a[i];
            r1 += 2;
        } else {
            break;
        }
    }
    ll r2 = 0, p2 = p;
    forxyd(i, 1, n-1, 2) {
        if (p2 >= a[i]) {
            p2 -= a[i];
            r2 += 2;
        } else {
            break;
        }
    }
    // DUMP(p1, p2, r1, r2);
    ll ans = std::max(r1, r2);
    col(ans);
}
ll Cal2(ll x, ll y, ll px) {
    assert(px >= b[x]);
    if (b[y] <= px) {
        DUMP("cal2", y);
        return y;
    }

    // b[y] > px
    while (x < y) {
        ll h = (x+y) / 2;
        if (px >= b[h]) {
            x = h + 1;
        } else {
            y = h;
        }
    }
    DUMP("cal2", x-1);
    return x-1;
}
ll Cal(ll x) {
    ll r1 = 0;
    auto px = p;
    forxyd(i, x+k, n, k) {
        if (a[i] > px) {
            break;
        }
        px -= a[i];
        r1 += k;
    }

    ll r2 = Cal2(0, x, px);
    DUMP("cal", x, r1, r2);
    r1 += r2;
    return r1;
}

void Solve() {
    std::cin >> n >> p >> k;
    for1(i, n) {
        std::cin >> a[i];
    }
    std::sort(a+1, a+1+n);
    Vec vec(a+1,a+1+n);
    DUMP(vec);

    b[0] = 0;
    for0(i, k) {
        b[i] = b[i-1] + a[i];
    }

    ll l = 0, r = k-1;
    auto vl = Cal(l);
    auto vr = Cal(r);
    auto mx = std::max(vl, vr);
    DUMP(mx, l, r, vl, vr);
    while (l < r) {
        ll h = (l+r)/2;
        auto v = Cal(h);
        if (v > mx) {
            mx = v;
            l = h + 1;
        } else {
            r = h;
        }
        DUMP(h, v, l, r, mx);
    }
    col(mx);
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
