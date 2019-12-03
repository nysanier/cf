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
// const int N = 1e6 + 9;
int c, m, x;
// int a[N];

bool Check(int a, int b) {
    if (a == b) return true;
    if (a == b - 1) return true;
    if (a == b + 1) return true;

    return false;
}

void Solve() {
    scanf("%d %d %d", &c, &m, &x);
    int d = std::min(c, m);
    c -= d;
    m -= d;
    x += c + m;
    if (d <= x) {
        printf("%d\n", d);
        return;
    }

    // d > x

    // remove 1 from d, but add 2 to x
    // f = d - n ~= x + 2n   --> 3n <= d-x
    int n = (d - x) / 3;  // find the min n;

    std::set<int> setx;
    for (int i = -3; i <= 3; ++i) {
        int n2 = n + i;
        if (n2 < 0) {
            continue;
        }
        int a = d - n2;
        int b = x + 2 * n2;
        if (Check(a, b)) {
            // printf("%d %d ok\n", a, b);
            setx.insert(n2);
        }
    }

    int n3 = *setx.begin();
    int ans = std::min(d - n3, x + 2 * n3);
    printf("%d\n", ans);
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
