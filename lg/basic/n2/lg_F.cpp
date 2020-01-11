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
ll p;  // 当前复杂度, 0: O(1), 1: O(n^1), w: O(n^w)
St pst;  // 可能有个for块，那么计算最大的那个for块的复杂度
ll ff;  // 如果上层for是不可能执行的，那么内嵌的for不计算复杂度
std::set<std::string> vars_st;  // 当前在用变量集合
std::vector<std::string> vars_vec;  // 当前在用变量顺序
Mp mp;  // 指示当前变量是否需要进行p+1，这样end的是否就知道是否要进行p-1操作了
void Init() {}
bool Work(const std::string& s) {
    // 处理end行
    if (s == "E") {
        // DUMP("END");
        auto sz = vars_vec.size();
        if (sz == 0) return false;  // end多于for
        // 无效for内部的for不用调整p
        if (ff == 0 && mp[sz]) p -= 1;  // 有效的for且曾经p+1过
        if (ff > 0 && sz == ff) ff = 0;  // 取消无效for标记
        auto last = vars_vec[sz-1];
        vars_st.erase(last);
        vars_vec.resize(sz-1);
        return true;
    }

    // 处理for行
    // DUMP("FOR");
    std::istringstream strin(s);
    std::string f, i, x, y;
    if (strin >> f >> i >> x >> y) ;
    else assert(0);  // F i x y 必须有4个变量
    assert(f == "F");
    // 检查变量冲突
    if (vars_st.find(i) != vars_st.end())
        return false;

    // 记录当前在用的变量
    vars_st.insert(i);
    vars_vec.push_back(i);
    mp[vars_vec.size()] = 0;  // 不用计算复杂度

    // 如果上层for存在无效，那么内嵌for不再计算复杂度
    if (ff > 0) {
        return true;
    }

    // 计算复杂度
    if (y == "n") {
        if (x != "n") {
            p += 1;  // a n 这种情况p才+1
            mp[vars_vec.size()] = 1;  // 需要计算复杂度
            pst.insert(p);  // 新增的for才计算复杂度，否则前面已经计算了
        }
        return true;
    }
    assert(y != "n");
    if (x == "n") {
        ff = vars_vec.size();  // 本层for无效，对内嵌的for有指导作用
        return true;
    }
    auto a = std::stoi(x);
    auto b = std::stoi(y);
    if (a > b) {
        ff = vars_vec.size();  // 两个常数，且a>b，无效for
        return true;
    }
    return true;
}
void Solve() {
    std::vector<std::string> lines;
    ll l;
    std::string ps;  // 参考值
    std::cin >> l >> ps;
    std::string line;
    std::getline(std::cin, line);  // 把str后面的行结束符先处理掉
    for0(i, l) {
        std::getline(std::cin, line);
        lines.push_back(line);
    }

    p = 0;
    pst = {0};  // 默认复杂度O(1)
    ff = 0;  // 默认没有一个变量是空循环
    vars_st.clear();
    vars_vec.clear();
    for (auto& s : lines) {
        if (!Work(s)) {  // 变量有冲突
            col("ERR");
            return;
        }
    }
    if (vars_vec.size() > 0) {
        col("ERR");  // end少于for
        return;
    }
    // 判定复杂度
    DUMP(pst, ps);
    p = *--pst.end();  // 取最大值
    if (p == 0 && ps == "O(1)") {
        col("Yes");
        return;
    }
    int w;
    sscanf(ps.c_str(), "O(n^%d)", &w);
    DUMP(w);
    if (p == w) col("Yes");
    else col("No");
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
    std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
