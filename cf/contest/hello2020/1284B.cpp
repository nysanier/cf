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
const ll N = 1e5 + 9;  // n^2 会超时!!!  nlogn : 78ms!!!
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
ll n;
struct S {
    ll a = 1e6;
    ll b = 0;
    bool c = false;
    bool operator<(const S& rhs) const {
        return a < rhs.a;
    }
};
// namespace std {
//     std::string to_string(const struct S& s) {
//         return "{a=" + std::to_string(s.a) + 
//     }
// }
S s[N];
ll f[N];
void Init() {}
void Solve() {
    std::cin >> n;
    ll len, t;
    for0(i, n) {
        std::cin >> len;
        for0(j, len) {
            std::cin >> t;
            if (t > s[i].a) s[i].c = true;
            s[i].a = std::min(s[i].a, t);
            s[i].b = std::max(s[i].b, t);
        }
    }

    std::sort(s, s+n);
    for0(i, n) {
        if (i == 0) {
            if (s[i].c) f[i] = 1;
            else f[i] = 0;
            continue;
        }
        f[i] = f[i-1] + (s[i].c ? 1 : 0);
    }
    Vec vf(f, f+n);
    DUMP(vf);

    ll ans = 0;
    for0(i, n) {  // for b
        if (s[i].c) {
            ans += n;
            continue;
        }
        if (s[i].b > s[n-1].a) {
            ans += n;
            continue;
        }
        if (s[i].b <= s[0].a) {
            ans += f[n-1];
            continue;
        }
        ll l = 0;  // s[l].a < b
        ll r = n-1;  // s[r].a >= b
        while (l < r) {  // locate a
            auto h = (l+r) / 2;
            if (s[h].a < s[i].b)
                l = h + 1;
            else
                r = h;
        }
        assert(l > 0);
        ans += l;
        ans += f[n-1] - f[l-1];
    }
    col(ans);

    // ll cnt = 0;
    // for0(i, n) for0(j, n) {
    //     if (c[i] || c[j] || a[i] < b[j]) cnt += 1;
    // }
    // col(cnt);
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
