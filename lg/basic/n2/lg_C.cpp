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
const ll N = 25*2500 + 9;
ll a;
ll b;
void Init() {}
bool Check(ll x) {
    if (a < x && b < x) return false;
    if (a == x && b <= x-2) {
        printf("%d:%d\n", a, b);
        a = 0;
        b = 0;
        return true;
    }
    if (a <= x-2 && b == x) {
        printf("%d:%d\n", a, b);
        a = 0;
        b = 0;
        return true;
    }
    if (a >= b+2 || b >= a+2) {
        printf("%d:%d\n", a, b);
        a = 0;
        b = 0;
        return true;
    }
    return false;
}
bool Check11() {
    return Check(11);
}
bool Check21() {
    return Check(21);
}
void Solve() {
    std::string all;
    std::string str;
    while (std::cin >> str) {
        all.append(str);
    }

    // 11
    a = 0;
    b = 0;
    for (auto c : all) {
        if (c == 'E') break;
        if (c == 'W') a += 1;
        else b += 1;
        Check11();
    }
    // if (a != 0 || b != 0)
        printf("%d:%d\n", a, b);
    puts("");
    // 21
    a = 0;
    b = 0;
    for (auto c : all) {
        if (c == 'E') break;
        if (c == 'W') a += 1;
        else b += 1;
        Check21();
    }
    // if (a != 0 || b != 0)
        printf("%d:%d\n", a, b);
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
