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

// 通过中序列表，可以推导出n中树的结构，根据题意，对这些树计算value，取其中的最大值即可
// 优化不出来了！！！
// -------------------------------------------------
struct Node {
    ll id{-1};
    ll val{0};
    ll left{-1};  // -1: 空节点
    ll right{-1};
};
const ll N = 30 + 9;
ll n;
// ll a[N];
Node a[N];
std::vector<ll> gl[N], gr[N];  // 最多N层
std::vector<ll> gvl[N], gvr[N];  // 最多N层
void Init() {
    for0(i, N) gl[i].reserve(N);
    for0(i, N) gr[i].reserve(N);
}
// 通过中序遍历，来构造各种可能的树结构，由于要求的值=vl*vr+vc, vl/vr可以分别计算最大值
// 在区间[l, r]上构造一个树，[l,r]表示这棵树的中序遍历
// 在[l, r]中选出来的根节点，挂到c上
ll Make(ll k, ll l, ll r, std::vector<ll>& vec) {
    assert(l <= r);
    vec.clear();
    if (l == r) {
        vec.push_back(l);
        return a[l].val;
    }
    if (l + 1 == r) {
        vec.push_back(l);
        vec.push_back(r);
        return a[l].val + a[r].val;
    }
    // 任何一个节点都可能作为根节点
    ll c = -1;
    ll v = -1;
    // std::vector<ll> vecl, vecr;
    forxy(i, l+1, r-1) {
        // std::vector<ll> tl, tr;
        auto vl = Make(k+1, l, i-1, gl[k+1]);
        auto vr = Make(k+1, i+1, r, gr[k+1]);
        ll nv = vl * vr + a[i].val;
        if (nv > v) {
            v = nv;
            c = i;  // 记录左右子树的前序排列
            // vecl.swap(gl[k+1]); vecr.swap(gr[k+1]);
            gvl[k].swap(gl[k+1]); gvr[k].swap(gr[k+1]);
        }
    }
    vec.push_back(c);
    vec.insert(vec.end(), gvl[k].begin(), gvl[k].end());
    vec.insert(vec.end(), gvr[k].begin(), gvr[k].end());
    return v;
}

ll Make2(ll& c, ll l, ll r) {
    if (l > r) {
        c = -1;
        return 0;
    }
    // 任何一个节点都可能作为根节点
    ll v = -1;
    c = -1;
    forxy(i, l, r) {
        auto vl = Make2(a[i].left, l, i-1);
        auto vr = Make2(a[i].right, i+1, r);
        ll p = vl * vr;
        if (vl && !vr) p = vl;
        else if (vr && !vl) p = vr;
        auto nv = p + a[i].val;
        if (nv > v) {
            v = nv;
            c = i;  // 记录左右子树的前序排列
        }
    }
    return v;
}
void Solve() {
    std::cin >> n;
    for1(i, n) {
        std::cin >> a[i].val;
        a[i].id = i;
    }
    std::vector<ll> vec;
    auto ans = Make(0, 1, n, vec);
    col(ans);
    for (auto v : vec) co(v);
    col("");
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
