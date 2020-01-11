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
const ll N = 2e5 + 9;
std::string str;
ll p1, p2, p3;
void Init() {}
// 小写字母处理
std::string Calc1(char a, char b) {
    if (a+1 == b) return "";  // 删除'-'
    std::string r;
    char x = a + 1;
    if (p1 == 2) x = std::toupper(x);
    else if (p1 == 3) x = '*';
    for (a += 1; a < b; ++a) {
        for0(i, p2)
            r.push_back(x);
        if (x != '*') x += 1;
    }
    if (p3 == 2) std::reverse(r.begin(), r.end());
    return r;
}
// 数字处理
std::string Calc2(char a, char b) {
    if (a+1 == b) return "";  // 删除'-'
    std::string r;
    char x = a + 1;
    if (p1 == 3) x = '*';
    for (a += 1; a < b; ++a) {
        for0(i, p2)
            r.push_back(x);
        if (x != '*') x += 1;
    }
    if (p3 == 2) std::reverse(r.begin(), r.end());
    return r;
}
void Solve() {
    std::cin >> p1 >> p2 >> p3;
    std::cin >> str;
    std::string ans;
    for (ll i = 0; i < str.size(); ++i) {
        if (str[i] != '-') {
            ans.push_back(str[i]);
            continue;
        }
        assert(str[i] == '-');
        if (ans.size() == 0 || i == str.size()-1) {  // last or first
            ans.push_back(str[i]);
            continue;
        }
        auto a = ans[ans.size()-1];
        auto b = str[i+1];
        if (a>='a' && a<='z' && b>='a' && b<='z' && b>a) {  // alpha
            auto v = Calc1(a, b);
            ans.append(v);
            continue;
        }
        if (a>='0' && a<='9' && b>='0' && b<='9' && b>a) {  // digit
            auto v = Calc2(a, b);
            ans.append(v);
            continue;
        }
        ans.push_back(str[i]);
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
