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
const ll N = 1e5 + 9;
ll jg[N], xl[N];
ll CB, XL;
void Init() {
   memset(jg, 0, sizeof(jg)); 
   memset(xl, 0, sizeof(xl)); 
}
// 所以直接来个暴力枚举的算法：
// 1：把用户输入的价格和销量通通存进数组里。
// 2：如果发现有的价格和销量用户没输入则按线性的规则自己写入。
// 3：在用户输入的最大价格后面按用户输入的递减数量把最后所有销量不为零的价格补充完整。
// 4：现在，你已经有了一个存有所有销量大于等于零的价格-销量表。
// 5：从1/-1开始枚举所有可能的补贴或税收，并看看在每种税收或补贴下总利润最高的价格是不是政府预期价，如果是则打印。（因为从最小的开始找的）

// 找到这个调控方法x，使预期价格获得的总利润最高
/*
(31-28+x)*110 >= (28-28+x)*130
(31-28+x)*110 >= (29-28+x)*125  销量需要自行推导（插值）
(31-28+x)*110 >= (30-28+x)*120
(31-28+x)*110 >= (31-28+x)*110
(31-28+x)*110 >= (32-28+x)*105  销量需要自行推导（递减15）
(yq-CB+x)*xl[yq] >= (i-CB+x)*xl[i] : i>=CB
*/
Mp mp;  // jg -> xl
ll jg_end;
ll delta;  // 递减
void Fill() {
    // 插值
    auto it = mp.begin();
    auto it2 = it;
    for (++it2; it2 != mp.end(); it=it2,++it2) {
        auto td = it2->second - it->second;
        auto c = it2->first - it->first;
        auto d = td / c;
        forxy(i, -it2->first+1, -it->first-1) {
            xl[i] = it2->second - d * (i+it2->first);
        }
    }
    // 计算最大值
    jg_end = -mp.begin()->first;
    ll xl_end = mp.begin()->second;
    for (;;) {
        if (xl_end < delta) break;
        jg_end += 1;
        xl[jg_end] = xl_end - delta;
        xl_end -= delta;
    }
    DUMP(jg_end, xl_end);
    Vec vec(xl+CB, xl+jg_end+1);
    DUMP(vec);
}
// i >= x
ll Int1(double x) {
    if (x < -1e8) return 0;
    if (x < 0) {
        // i>=-3.3 -> i>=-3
        return -floor(-x);
    }
    // i>=3.3 -> i>=4
    return ceil(x);
}
// i <= x
ll Int2(double x) {
    if (x < -1e8) return 0;
    if (x < 0) {
        // i<=-3.3 -> i<=-4
        return -ceil(-x);
    }
    // i<=3.3 -> i<=3
    return floor(x);
}
void Solve() {
    ll yq;
    std::cin >> yq;
    std::cin >> CB >> XL;
    jg[CB] = 1;
    xl[CB] = XL;
    mp[-CB] = XL;  // max
    for (;;) {
        ll x, y;
        std::cin >> x >> y;
        if (x==-1 || y==-1) break;
        jg[x] = 1;
        xl[x] = y;
        mp[-x] = y;
    }
    std::cin >> delta;
    // 构造所有的值
    Fill();
    // 计算所有不等式，得到x的结果范围
    double m1 = -1e8, m2 = 1e8;
    // ll end = -1;  // 从哪些价格去算
    // (yq-CB+x)*xl[yq] >= (i-CB+x)*xl[i] : i>=CB
    forxy(i, CB, jg_end) {  // i是价格枚举
        // ax >= b
        auto a = xl[yq] - xl[i];
        if (a == 0) continue;
        auto b = (i-CB)*xl[i] - (yq-CB)*xl[yq];
        auto c = double(b) / a;
        DUMP(i, a, b, c);
        if (a > 0)  // x >= b/a
            m1 = std::max(m1, c);
        else  // x <= b/a
            m2 = std::min(m2, c);
    }
    DUMP(m1, m2);
    ll x1 = Int1(m1);
    ll x2 = Int2(m2);
    DUMP(x1, x2);
    if (x1 > x2) {
        col("NO SOLUTION");
        return;
    }

    if (x1 <= 0 && x2 >= 0) {
        col(0);
        return;
    }
    if (x2 < 0) {
        col(x2);
        return;
    }
    // x1 > 0
    col(x1);
    return;
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
