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

/*
解题思路:
    1. 迭代的计算A-N(0-N-1)，复杂度O(26!)，可能要考虑剪枝
    2. 剪枝策略：最高位取值后，然后算一下后面的位是否会超出范围
    3. 
解题步骤:
    1. 
    2. 
    3. 
*/
// -------------------------------------------------
const ll N = 26 + 9;
ll n;
std::string a, b, c;
ll v[N];
ll vis[N];  // 0-26是否已经被占用
bool flag;
void Init() {
    memset(vis, 0, sizeof(vis));
}
bool Check() {
    // co("check:");
    // for0(i, n) co(v[i]);
    // col("");
    // Vec vec(v, v+n);
    // if (vec == Vec{1,0,3,4,2})
    //     DUMP(vec);
    ll br = 0;
    for0r(i, n) {
        auto vab = v[a[i]] + v[b[i]];
        auto vabm = (vab + br) % n;
        auto vc = v[c[i]];
        // if (vec == Vec{1,0,3,4,2})
        //     DUMP(i, vab, vabm, vc);
        if (vabm != vc) {
            // if (vec == Vec{1,0,3,4,2})
            //     DUMP("vabm != vc");
            return false;
        }
        if (vab + br >= n)  // 进位
            br = 1;
        else
            br = 0;
    }
    if (br == 1) {
        // if (vec == Vec{1,0,3,4,2})
        //     DUMP("br == 1");
        return false;  // 最后不能进位
    }
    return true;
}
void Dfs(ll k) {
    if (k == n) {
        if (Check()) {
            flag = true;
            for0(i, n) co(v[i]);
            col("");
            return;
        }
    }
    if (flag) return;
    for0(i, n) {
        if (!vis[i]) {
            vis[i] = 1;
            v[k] = i;
            Dfs(k+1);
            if (flag) return;
            vis[i] = 0;  // 回溯
        }
    }
}
void Solve() {
    std::cin >> n;
    std::cin >> a >> b >> c;
    for0(i, n) {
        a[i] -= 'A';
        b[i] -= 'A';
        c[i] -= 'A';
    }
    flag = false;
    Dfs(0);
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
