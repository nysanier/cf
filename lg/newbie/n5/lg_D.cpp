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
void Reverse(std::string& str) {
    if (str == "0")
        return;
    auto s = str;
    std::reverse(s.begin(), s.end());
    auto p = s.find_first_not_of('0');
    // assert(p != s.npos);
    if (p == s.npos) {
        str = "0";
        return;
    }
    str = s.substr(p);
}
void RemoveTailZero(std::string& str) {
    if (str == "0")
        return;
    auto s = str;
    auto p = s.find_last_not_of('0');
    // assert(p != s.npos);
    if (p == s.npos) {
        str = "0";
        return;
    }
    p += 1;
    str = s.substr(0, p);
}
void Solve() {
    std::string s;
    // s = "12340000"; Reverse(s); DUMP(s);
    // s = "0"; Reverse(s); DUMP(s);
    // s = "12340000"; RemoveTailZero(s); DUMP(s);
    // s = "0"; RemoveTailZero(s); DUMP(s);
    std::cin >> s;
    auto p = s.find('.');
    if (p != s.npos) {
        auto a = s.substr(0, p);
        auto b = s.substr(p+1);
        Reverse(a);
        Reverse(b);
        RemoveTailZero(b);
        auto c = a + "." + b;
        col(c);
        return;
    }

    p = s.find('/');
    if (p != s.npos) {
        auto a = s.substr(0, p);
        auto b = s.substr(p+1);
        Reverse(a);
        Reverse(b);
        auto c = a + "/" + b;
        col(c);
        return;
    }

    p = s.find('%');
    if (p != s.npos) {
        auto a = s.substr(0, p);
        Reverse(a);
        auto c = a + "%";
        col(c);
        return;
    }

    Reverse(s);
    col(s);
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
