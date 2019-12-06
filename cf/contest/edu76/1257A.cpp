#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)

#ifndef ONLINE_JUDGE
# define dbg(fmt, args...) printf("***DEBUG*** " fmt "\n", ##args)
#else
# define dbg(fmt, args...)
#endif
#define dump(e) dbg("dump: " #e "=%d", e)

using ll = long long;
using Vi = std::vector<int>;
using Pii = std::pair<int, int>;
using Si = std::set<int>;

// -------------------------------------------------
int n, x, a, b;

void Solve() {
    scanf("%d %d %d %d", &n, &x, &a, &b);
    if (a > b) std::swap(a, b);
    auto m1 = std::min(a - 1, x);
    dump(m1);
    a -= m1; x -= m1;
    auto m2 = std::min(n - b, x);
    dump(m2);
    b += m2; x -= m2;
    printf("%d\n", b - a);
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

#if 1
    int t;
    scanf("%d", &t);
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
