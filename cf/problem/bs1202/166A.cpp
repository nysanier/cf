#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)
#define PB push_back
#define FI first
#define SE second

#ifndef ONLINE_JUDGE
# define dbg(fmt, args...) printf("***DEBUG*** " fmt "\n", ##args)
#else
# define dbg(fmt, args...)
#endif
// #define dump(e) dbg("dump: " #e "=%d", e)

using ll = long long;
using Vi = std::vector<int>;
using Pi = std::pair<int, int>;
using Si = std::set<int>;
using Mi = std::map<int, int>;

// -------------------------------------------------
const int N = 5e1 + 9;
int n, k;
Pi a[N];
void Solve() {
    scanf("%d %d", &n, &k);
    int p, t;
    for0(i, n) {
        scanf("%d %d", &p, &t);
        a[i] = {-p, t};
    }
    std::sort(a, a + n);
    auto v = a[k - 1];
    auto m1 = std::lower_bound(a, a + n, v);
    auto m2 = std::upper_bound(a, a + n, v);
    auto ans = m2 - m1;
    dbg("m1 = %d, m2 = %d\n", int(m1 - a), int(m2 - a));
    for0(i, n) {
        dbg("[%d] (%d,%d)", i, a[i].FI, a[i].SE);
    }
    // output
    printf("%d\n", (int)ans);
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

#if 0
    int t;
    scanf("%d", &t);
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
