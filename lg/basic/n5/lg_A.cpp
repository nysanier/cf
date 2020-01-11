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
const ll N = 6 + 9;
const std::string STR1 = "one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty";
const std::string STR2 = "a both another first second third";
std::map<std::string, ll> mp;
ll n;
std::string a[N];
void Init() {
    std::istringstream strin1(STR1);
    std::string str;
    for (ll i = 1; i <= 20; ++i) {
        if (strin1 >> str) ;
        else assert(0);
        mp[str] = i;
    }
    std::istringstream strin2(STR2);
    for0(k, 2) for1(i, 3) {
        if (strin2 >> str) ;
        else assert(0);
        mp[str] = i;
    }
}
std::string ToLower(const std::string& str) {
    std::string r;
    for (auto ch : str) {
        r.push_back(std::tolower(ch));
    }
    return r;
}
void Solve() {
    n = 6;
    for0(i, n+1) {
        std::cin >> a[i];
    }
    Vec res;
    for0(i, n) {
        auto it = mp.find(a[i]);
        if (it == mp.end()) continue;
        auto v = it->second;
        auto v2 = v * v;
        auto v3 = v2 % 100;
        res.push_back(v3);
    }
    std::sort(res.begin(), res.end());
    ll ans = 0;
    for (auto v : res)
        ans = 100 * ans + v;
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
