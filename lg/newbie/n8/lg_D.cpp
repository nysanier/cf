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
// 规范表达式: ax+b=cx+d
/*
步骤:
    -1. 会不会连续两个'-': 1--2a这样?
    0. 去掉所有空格
    1. 通过'='拆分为两个部分 X=Y
    2. X/Y每个部分通过'+'/'-'拆分为多个部分，每个部分相加就是X/Y
    3. 对每个部分判断最后是否有字母，来确定变量和常数项，整理变量和常数项，得到ax+b=cx+d
    4. x=double(d-b)/(a-c)
*/
void RemoveSpace(std::string& str) {
    auto s = str;
    str.clear();
    for (auto c : s)
        if (c != ' ')
            str.push_back(c);
}
// by '='
void Split1(const std::string& str, std::string& X, std::string& Y) {
    auto p = str.find('=');
    assert(p < str.size());
    X = str.substr(0, p);
    Y = str.substr(p+1);
}
// by '+'/'-'
// v1: 变量项, v2: 常数项
void Split2(const std::string& str, std::vector<std::string>& v1, std::vector<std::string>& v2) {
    auto s = str + "+0"; // 岗哨，方便处理最后一个数据
    if (s[0] != '+' && s[0] != '-') s = "+" + s; // 规范化方便后面处理
    DUMP("Split2", str, s);
    v1.clear();
    v2.clear();
    std::string::size_type p1 = 1;
    for (;;) {
        auto p2 = s.find_first_of("+/-", p1);
        DUMP("--", s[p1], p1, p2);
        if (p2 == s.npos) break;
        auto e = s.substr(p1-1, p2-p1+1);
        if (std::isalpha(e[e.size()-1])) v1.push_back(e);  // 带变量
        else v2.push_back(e);
        p1 = p2 + 1;
    }
}
// 合并系数
void Merge(const std::vector<std::string>& vec, ll& v) {
    v = 0;
    for (auto& str : vec) {
        try {
            v += std::stol(str);
        } catch (...) {
            if (str[0] == '-') v += -1;
            else v += 1;
        }
    }
}
void Solve() {
    // std::vector<std::string> vec{
    //     // 异常项, 暂时不考虑这种情况
    //     "++1a",
    //     "--1a",

    //     // 正常
    //     "1a",
    //     "+1a",
    //     "-1a",

    //     "6a",
    //     "+6a",
    //     "-6a",

    //     // 异常
    //     "a",
    //     "+a",
    //     "-a",
    // };
    // for (auto& str : vec) {
    //     ll v = 0;
    //     try {
    //         v = std::stol(str);
    //     } catch (...) {
    //         DUMP("except");
    //         if (str[0] == '-') v = -1;
    //         else v = 1;
    //     }
    //     DUMP(str, v);
    // }
    std::string exp;
    std::getline(std::cin, exp);
    DUMP("before", exp);
    RemoveSpace(exp);
    DUMP("after", exp);
    // 排除这种异常情况
    {
        auto p1 = exp.find("--");
        auto p2 = exp.find("++");
        assert(p1 == exp.npos && p2 == exp.npos);
    }
    std::string X, Y;
    Split1(exp, X, Y);
    DUMP(X, Y);
    std::vector<std::string> AX, B, CX, D;
    Split2(X, AX, B);
    Split2(Y, CX, D);
    DUMP(AX, B, CX, D);
    ll a, b, c, d;
    Merge(AX, a);
    Merge(B, b);
    Merge(CX, c);
    Merge(D, d);
    DUMP(a, b, c, d);
    auto ans = double(d-b)/(a-c);
    std::string name;
    if (!AX.empty()) name = AX[0];
    else name = CX[0];
    printf("%c=%.3lf\n", name[name.size()-1], ans==0?0:ans);
    // 为什么: 计算错误了?
    // Wrong Answer. wrong answer On line 1 column 3, read -, expected 0.
    // 因为0/-1=-0!!!!!!!!!
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
