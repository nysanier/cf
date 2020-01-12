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
ll n;
std::string a[N];
void Init() {}
// 有前缀的处理方案
// 32-321, 那么 32 > 321
// 32-3233, 那么 32 < 3233
bool Less(const std::string& a, const std::string& b) {
    assert(a.size() < b.size());
    auto p = b.find(a);
    if (p > 0) return a < b;
    auto c = b.substr(a.size());
    return a < c;
}
bool Cmp(const std::string& a, const std::string& b) {
    if (a.size() == b.size()) return a < b;
    if (a.size() < b.size()) return Less(a, b);
    return !Less(b, a);
}
void Solve() {
    std::cin >> n;
    for0(i, n) {
        std::cin >> a[i];
    }
    std::sort(a, a+n, Cmp);
    std::vector<std::string> vec(a, a+n);
    DUMP(vec);
    std::string ans;
    for0r(i, n) {
        ans += a[i];
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
