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

// 回溯一下即可
// -------------------------------------------------
const ll N = 13 + 9;
ll n;
ll r[N], c[N];  // 行列标记
ll a[2*N];  // 斜线标记，r+c, [1+1, n+n], 共2n-1个, 都-1, -> [1, 2n-1]
ll b[2*N];  // 反斜线标记, r-c, [1-n, n-1], 共2n-1个, 都+n, -> [1, 2n-1]
ll v[N];
// 不能使用set啊，超过10以后，字典序排列有问题了，比如10会排的前面!!!
std::vector<std::string> vec;
void Init() {
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
}
std::string Make() {
    std::string ret = std::to_string(v[1]);
    for (int i = 2; i <= n; ++i) {
        ret += " " + std::to_string(v[i]);
    }
    return ret;
}
void Dfs(int i) {
    if (i == n+1) {
        auto ret = Make();
        vec.push_back(ret);
        return;
    }

    for (int j = 1; j <= n; ++j) {
        if (r[i]) continue;
        if (c[j]) continue;
        if (a[i+j-1]) continue;
        if (b[i-j+n]) continue;
        r[i] = 1; c[j] = 1; a[i+j-1] = 1; b[i-j+n] = 1;
        v[i] = j;
        Dfs(i+1);
        r[i] = 0; c[j] = 0; a[i+j-1] = 0; b[i-j+n] = 0;
    }
}
void Solve() {
    std::cin >> n;
    Dfs(1);

    auto it = vec.begin();
    for (int i = 0; i < 3 && it != vec.end(); ++i, ++it) {
        col(*it);
    }
    col(vec.size());
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
