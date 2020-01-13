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
// const ll N = 2e5 + 9;
/*
k=2:
      --   --        --   --   --   --   --   -- 
   |    |    | |  | |    |       | |  | |  | |  |
   |    |    | |  | |    |       | |  | |  | |  |
      --   --   --   --   --        --   --      
   | |       |    |    | |  |    | |  |    | |  |
   | |       |    |    | |  |    | |  |    | |  |
      --   --        --   --        --   --   -- 
k=1:

*/
void Init() {}
// 行上的几个可能性
enum Type {
    T_000,  // 1[1,3,5], 4[1,5], 7[3,5], 0[3]
    T_0_0,  // 2[1,3,5], 3[1,3,5], 4[3], 5[1,3,5], 6[1,3,5], 7[1], 8[1,3,5], 9[1,3,5], 0[1,5]
    T_001,  // 1[2,4], 2[2], 3[2,4], 4[4], 5[4], 7[2,4], 9[4]
    T_100,  // 2[4], 5[2], 6[2]
    T_101,  // 4[2], 6[4], 8[2,4], 9[2], 0[2,4]
};
// 构造行
std::string Row(Type type, ll sz) {
    switch (type) {
    case T_000:
        return " " + std::string(sz, ' ') + " ";
    case T_0_0:
        return " " + std::string(sz, '-') + " ";
    case T_001:
        return " " + std::string(sz, ' ') + "|";
    case T_100:
        return "|" + std::string(sz, ' ') + " ";
    case T_101:
        return "|" + std::string(sz, ' ') + "|";
    }
    assert(0);
    return "";
}
// 数字的最大高度
ll Height(ll sz) {
    auto ret = 1 + sz + 1 + sz + 1;
    return ret;
}
// 获取sz为1的时候r的值
ll Descale(ll sz, ll r) {
    auto h = Height(r);
    assert(r > 0 && r <= h);
    if (r == 1) return 1;
    if (r <= 1 + sz) return 2;
    if (r <= 1 + sz + 1) return 3;
    if (r <= 1 + sz + 1 + sz) return 4;
    return 5;
}
// x 什么数字
// 这个数字的size
// r第几行
std::string Get(ll x, ll sz, ll r) {
    auto q = Descale(sz, r);
    assert(q >= 1 && q <= 5);
    std::string ret;
    switch (x) {
    case 1:
        if (q==1||q==3||q==5) return Row(T_000, sz);
        else return Row(T_001, sz);
    case 2:
        if (q==1||q==3||q==5) return Row(T_0_0, sz);
        else if (q==2) return Row(T_001, sz);
        else return Row(T_100, sz);
    case 3:
        if (q==1||q==3||q==5) return Row(T_0_0, sz);
        else return Row(T_001, sz);
    case 4:
        if (q==1||q==5) return Row(T_000, sz);
        else if (q==3) return Row(T_0_0, sz);
        else if (q==4) return Row(T_001, sz);
        else return Row(T_101, sz);
    case 5:
        if (q==1||q==3||q==5) return Row(T_0_0, sz);
        else if (q==4) return Row(T_001, sz);
        else return Row(T_100, sz);
    case 6:
        if (q==1||q==3||q==5) return Row(T_0_0, sz);
        else if (q==2) return Row(T_100, sz);
        else return Row(T_101, sz);
    case 7:
        if (q==3||q==5) return Row(T_000, sz);
        else if (q==1) return Row(T_0_0, sz);
        else return Row(T_001, sz);
    case 8:
        if (q==1||q==3||q==5) return Row(T_0_0, sz);
        else return Row(T_101, sz);
    case 9:
        if (q==1||q==3||q==5) return Row(T_0_0, sz);
        else if (q==4) return Row(T_001, sz);
        else return Row(T_101, sz);
    case 0:
        if (q==3) return Row(T_000, sz);
        else if (q==1||q==5) return Row(T_0_0, sz);
        else return Row(T_101, sz);
    }
    assert(0);
    return "";
}
void Solve() {
    ll k;
    std::string str;
    std::cin >> k >> str;
    ll h = Height(k);
    for1(i, h) {
        std::string res = Get(str[0]-'0', k, i);
        for1(j, str.size()-1) {
            res += " " + Get(str[j]-'0', k, i);
        }
        col(res);
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
