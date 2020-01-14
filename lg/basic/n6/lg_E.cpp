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
const ll N = 3e4 + 9;
ll w;
ll n;
ll a[N];
Mst mst;
void Init() {}
void Solve() {
    std::cin >> w;
    std::cin >> n;
    for0(i, n) {
        std::cin >> a[i];
        mst.insert(a[i]);
    }

    ll ans = 0;
    while (!mst.empty()) {
        auto it = mst.begin();
        auto x = *it;
        mst.erase(it);
        auto y = w - x;  // 最多取y，不能超过y
        assert(y >= 0);
        if (mst.empty()) {
            ans += 1;
            y = -1;
            DUMP("empty", x, y);
            continue;
        }

        auto it2 = mst.lower_bound(y);
        // 当前的值都比y小，那么退而求其次，取其中一个最大的即可
        if (it2 == mst.end()) {
            y = *--it2;
            mst.erase(it2);
            ans += 1;
            DUMP("<y", x, y);
            continue;
        }

        // 看看是否还存在比y小的值
        if (*it2 > y) {
            if (*mst.begin() < y) {
                y = *--it2;
                mst.erase(it2);
            } else {  // 都比y大，那么x没有搭配了
                y = -1;
            }
            ans += 1;
            DUMP(">y", x, y);
            continue;
        }

        // 刚好取到=y这个值
        mst.erase(it2);
        ans += 1;
        DUMP("=y", x, y);
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
