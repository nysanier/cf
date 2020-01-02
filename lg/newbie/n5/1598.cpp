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
const ll N = 4e2 + 9;  // 最多400个字符
ll n;
ll a[26];
std::string s[401];
void Init() {
    s[0].push_back('A');
    for (char ch = 'B'; ch <= 'Z'; ++ch) {
        s[0].push_back(' ');
        s[0].push_back(ch);
    }
    for1(i, 400)
        s[i] = std::string(26*2-1, ' ');
    std::fill(a, a+26, 0);
}
void Solve() {
    std::string line;
    // 统计每个字符数量
    for0(i, 4) {
        std::getline(std::cin, line);
        for (auto ch : line) {
            if (ch>='A' && ch<='Z')
                a[ch-'A'] += 1;
        }
    }

    // 每个字符在对应位置上绘制星号(*)
    for0(i, 26) {
        for1(j, a[i]) {  // s[0] is ABCDEF
            s[j][i*2] = '*';
        }
    }

    // 去除星号后面的空格，如果没有星号(*)，那么置空
    for1(i, 400) {
        auto p = s[i].find_last_of('*');
        if (p == s[i].npos) s[i].clear();
        s[i] = s[i].substr(0, p+1);
    }

    // 反向打印，没有星号的行不打印
    for0r(i, 401) {
        if (s[i].empty()) continue;
        else col(s[i]);
    }
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
