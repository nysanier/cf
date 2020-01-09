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
ll n;
ll a[N];
std::vector<std::string> res;
void Init() {}

std::string Normal(ll a, ll b) {
    if (a == 0) return "0";
    if (b == 0) {
        // +a/-a
        if (a > 0) return "+" + std::to_string(a);
        else return std::to_string(a);
    }

    assert(abs(a) >= 1);
    assert(b >= 1);
    std::string pre;
    if (a == 1) pre = "+";
    else if (a == -1) pre = "-";
    else if (a > 1) pre = "+" + std::to_string(a);
    else pre = std::to_string(a);

    if (b == 1) return pre + "x";
    else return pre + "x^" + std::to_string(b);
}
// 1. 每一项先规范化, 0/+ax^b/-ax^b, a==0时: 0; a==1时: +x^b; b==1时: +ax; b==0时: +a
// 2. 拼接所有项,第一项如果是+, 那么不输出+号,其他项直接输出(丢弃0,如果都是0,那么输出一个0)
void Solve() {
    std::cin >> n;
    for0r(i, n+1) {
        std::cin >> a[i];
        auto s = Normal(a[i], i);
        if (s != "0") res.push_back(s);
    }

    if (res.empty()) {  // all 0!!
        col("0");
        return;
    }

    if (res[0][0] == '+') {
        printf("%s", res[0].c_str()+1);
    } else {
        printf("%s", res[0].c_str());
    }
    forxy(i, 1, res.size()-1) {
        printf("%s", res[i].c_str());
    }
    printf("\n");
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
