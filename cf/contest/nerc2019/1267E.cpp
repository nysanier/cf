#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
const int N = 1e2 + 9;

int n, m;
int a[N][N];
int dp[N][N][N];

// f(n, 0) = max(f1, f2)
// f1 = f(m-1, a[m][n]) + 1
// f2 = f(m-1, 0)

int f(int k, std::vector<int> vec) {
    assert(vec.size() == n);
    if (k == 0) {
        return 0;
    }

    std::vector<int> ex(n+1);
    for (auto idx : vec) {
        for1(i, n)
            ex[i] += a[idx][i];
    }
    for1(i, n-1) {
        if ()
    }

    return 0;
}

void Solve() {
    scanf("%d %d", &n, &m);
    for1(i, m)
        for1(j, n)
            scanf("%d", &a[m][j]);
    for0(i,n+1)
        a[0][i] = 0;

    memset(dp, -1, sizeof(dp));

    for0(i,n+1)
        dp[0][i] = 0;
    for1(i,m)
        dp[i][0] = 0;

    for1(i, m)
        for1(j, m) {
            int f2 = dp[i-1][0];

            dp[i][j] = f(i, a[i][n]);
        }
}

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
