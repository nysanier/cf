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
ll n, r, q;
ll w[N*2];  // 实力
// Pr pr[N*2];  // -s -> id
ll s[N*2];  // 分数
ll id[N*2];  // id
ll win[N], wi;
ll lose[N], li;
void Init() {}
void Solve() {
    std::cin >> n >> r >> q;
    for1(i, 2*n) {
        std::cin >> s[i];
        id[i] = i;
    }
    for1(i, 2*n) std::cin >> w[i];
    // std::sort(pr+1, pr+1+2*n);
    std::sort(id+1, id+1+2*n, [](ll id1, ll id2){
        if (s[id1] > s[id2]) return true;
        if (s[id1] == s[id2] && id1 < id2) return true;
        return false;
    });
    for1(i, r) {
        Vec vec{id+1, id+1+2*n};
        DUMP(vec);
        wi = 0;
        li = 0;
        forxyd(i, 1, 2*n, 2) {
            // win/lose都是有序的，进行归并即可
            auto id1 = id[i];
            auto id2 = id[i+1];
            if (w[id1] > w[id2]) {
                s[id1] += 1;
                win[wi++] = id1;
                lose[li++] = id2;
            } else {
                s[id2] += 1;
                win[wi++] = id2;
                lose[li++] = id1;
            }
        }
        // 归并排序，3个while!!
        ll a=0, b=0, c=1;
        while (a<n && b<n) {
            auto id1 = win[a];
            auto id2 = lose[b];
            if ((s[id1] > s[id2]) || (s[id1]==s[id2] && id1<id2)) {
                id[c++] = win[a++];
            } else {
                id[c++] = lose[b++];
            }
        }
        while (a < n)
            id[c++] = win[a++];
        while (b < n)
            id[c++] = lose[b++];
        // std::sort(pr+1, pr+1+2*n);
    }
    auto ans = id[q];
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
