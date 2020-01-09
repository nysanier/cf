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
const ll N = 100 + 9;
struct S {
    std::string name;
    ll qimo;  // 期末成绩
    ll banji;  // 班级评议
    std::string ganbu;  // 学生干部
    std::string xibu;  // 西部学生
    ll lunwen;  // 论文
    ll seq;  // 序号
    ll total;  // 个人总奖金
    void Read() {
        std::cin >> name >> qimo >> banji >> ganbu >> xibu >> lunwen;
    }
    void Calc() {
        total = 0;
        if (qimo > 80 && lunwen >= 1) total += 8000;
        if (qimo > 85 && banji > 80) total += 4000;
        if (qimo > 90) total += 2000;
        if (qimo > 85 && xibu == "Y") total += 1000;
        if (banji > 80 && ganbu == "Y") total += 850;
    }
    bool operator<(const S& rhs) const {
        return Pr{-total,seq} < Pr{-rhs.total,rhs.seq};
    }
};
ll n;
S s[N];
void Init() {}
void Solve() {
    std::cin >> n;
    ll sum = 0;
    for0(i, n) {
        s[i].Read();
        s[i].seq = i;
        s[i].Calc();
        sum += s[i].total;
    }
    std::sort(s, s+n);
    col(s[0].name);
    col(s[0].total);
    col(sum);
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
