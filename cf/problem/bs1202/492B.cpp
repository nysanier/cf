#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
using Vi = std::vector<int>;
using Vll = std::vector<ll>;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;

// -------------------------------------------------
const int N = 1e3 + 9;
int n, l;
int a[N];

void Solve() {
    scanf("%d %d", &n, &l);
    for0(i, n) scanf("%d", a + i);
    std::sort(a, a + n);
    std::set<int> setx;
    setx.insert(a[0]*2);
    setx.insert((l-a[n-1])*2);
    for1(i, n-1) {
        setx.insert(a[i]-a[i-1]);
    }
    auto ans = *--setx.end();  // the last one
    printf("%lf\n", ans / 2.0);
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
