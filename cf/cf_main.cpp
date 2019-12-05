#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)

#define debugf(fmt, args...) printf("***DEBUG*** " fmt, ##args)
// #define debugf(fmt, args...)

using ll = long long;
using Vi = std::vector<int>;
using Vll = std::vector<ll>;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;
using Si = std::set<int>;
using Sll = std::set<ll>;

// -------------------------------------------------
const int N = 1e6 + 9;
int n;
int a[N];

void Solve() {
    scanf("%d", &n);
    for0(i, n) {
        scanf("%d", a + i);
    }

    // output
    for0(i, n) {
        printf("%d ", a[i]);
    }
    printf("\n");
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
