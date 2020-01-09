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
struct Int {
    // 有0开头的?
    std::string s;
    void Fix() {
        auto p = s.find_first_not_of('0');
        if (p == s.npos) s = "0";
        else if (p != 0) s = s.substr(p);
    }
    // 票数多的排前面
    bool operator<(const Int& rhs) const {  // 这个是排前面的意思
        if (s.size() > rhs.s.size()) return true;
        if (s.size() < rhs.s.size()) return false;
        assert(s.size() == rhs.s.size());
        // 从高位开始比较，只要有一位不同，那么就可以判断大小了
        if (s > rhs.s) return true;
        if (s < rhs.s) return false;
        // for0(i, s.size()) {
        //     if (s[i] > rhs.s[i]) return true;
        //     if (s[i] < rhs.s[i]) return false;
        // }
        // 不能相等吧
        assert(0);
        return false;
    }
};
// namespace std {
//     std::string to_string(const Int& x) {
//         return x.s;
//     }
// }
const ll N = 20 + 9;
ll n;
std::pair<Int, ll> pr[N];  // 票数 -> 编号
void Init() {}
void Solve() {
    std::cin >> n;
    for1(i, n) {
        std::cin >> pr[i].first.s;
        // pr[i].first.Fix();
        pr[i].second = i;
    }
    std::sort(pr+1, pr+1+n);
    // std::vector<std::pair<Int, ll>> vec(pr, pr+n);
    // DUMP(vec);
    col(pr[1].second);
    col(pr[1].first.s);
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
