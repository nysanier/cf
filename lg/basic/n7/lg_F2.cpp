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
还是无法解决TLE问题
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
Vec seq;  // 搜索顺序
ll rseq[N];  // 字母对应的搜索顺序
St st;  // 安排seq时候辅助去重
bool flag;
void Init() {
    memset(vis, 0, sizeof(vis));
    memset(v, -1, sizeof(v));
}
bool Check() {
    ll cr = 0;
    for0r(i, n) {
        auto vab = v[rseq[a[i]]] + v[rseq[b[i]]];
        auto vabm = (vab + cr) % n;
        auto vc = v[rseq[c[i]]];
        if (vabm != vc) {
            return false;
        }
        if (vab + cr >= n)  // 进位
            cr = 1;
        else
            cr = 0;
    }
    if (cr == 1) {
        return false;  // 最后不能进位
    }
    return true;
}
bool CheckPartly() {
    ll l = 0;
    for (; l < n; ++l) {
        auto sa = rseq[a[l]];
        auto sb = rseq[b[l]];
        auto sc = rseq[c[l]];
        // DUMP("part", sa, sb, sc);
        if (!vis[sa] || !vis[sb] || !vis[sc]) break;  // 有一个字母还未确定下来
    }
    if (l == 0) return true;  // 还不能确定
    static ll cnt = 0;
    bool fdump = false;
    if (l > 0 && cnt++ < 15) {
        fdump = true;
    }

    if (fdump) {
        DUMP(l);
        co("a:");
        for0(i, n) {
            auto sa = rseq[a[i]];
            co(v[sa]);
        }
        col("");
        co("b:");
        for0(i, n) {
            auto sa = rseq[b[i]];
            co(v[sa]);
        }
        col("");
        co("c:");
        for0(i, n) {
            auto sa = rseq[c[i]];
            co(v[sa]);
        }
        col("");
    }
    ll br = 0;
    for0(x, l) {
        auto sa = rseq[a[x]];
        auto sb = rseq[b[x]];
        auto sc = rseq[c[x]];
        auto vab = v[sa] + v[sb];
        if (br == 1) {
            if (v[sa] + v[sb] < n) {
                if (fdump) DUMP("false", x, "br == 1");
                return false;  // 不够借位
            }
            vab -= n;
        }
        if (vab > v[sc]) {
            if (fdump) DUMP("false", x, "vab > v[sc]");
            return false;  // a或者b太大了，没有必要继续算了
        }
        else if (vab == v[sc]) br = 0;
        else if (vab + 1 == v[sc]) br = 1;
        else {
            if (fdump) DUMP("false", x, "else");
            return false;  // 太小了，无法靠进位
        }
    }

    if (fdump) DUMP("true");
    return true;
}
void Dfs(ll k) {
    if (k == n) {
        if (Check()) {
            flag = true;
            for0(i, n) co(v[rseq[i]]);
            col("");
            return;
        }
    }
    if (flag) return;
    for0(i, n) {
        if (vis[i]) continue;
        vis[i] = 1;
        v[k] = i;
        if (!CheckPartly()) {
            v[k] = -1;
            vis[i] = 0;  // 回溯
            continue;
        }
        Dfs(k+1);
        if (flag) return;
        v[k] = -1;
        vis[i] = 0;  // 回溯
    }
}
void Solve() {
    std::cin >> n;
    std::cin >> a >> b >> c;
    for0(i, n) {
        a[i] -= 'A';
        b[i] -= 'A';
        c[i] -= 'A';
        if (st.find(a[i]) == st.end()) {
            seq.push_back(a[i]);
            st.insert(a[i]);
        }
        if (st.find(b[i]) == st.end()) {
            seq.push_back(b[i]);
            st.insert(b[i]);
        }
        if (st.find(c[i]) == st.end()) {
            seq.push_back(c[i]);
            st.insert(c[i]);
        }
    }
    assert(st.size() == n);
    assert(seq.size() == n);
    for0(i, n)
        rseq[seq[i]] = i;
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
