#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
const int N = 1e1 + 9;

void Solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    vi a(n+1);
    vi s(n+1);
    const int remain = 240 - k;
    for1(i, n) a[i] = 5 * i;
    s[0] = 0;
    for1(i, n) s[i] = s[i-1] + a[i];

    if (s[n] <= remain) {
        printf("%d\n", n);
        return;
    }

    // here make sure s[j] > remain
    // find index i let sum[i] > remain but sum[i-1] <= remain
    int i = 0, j = n;
    while (i < j) {  // find the s[i]!!
        int h = (i + j) / 2;  // h maybe equal i, but can't be equal j
        if (s[h] <= remain) {
            i = h + 1;  // must move forward
        } else {
            j = h;  // must move forward
        }
    }

    assert(i >= 1);
    printf("%d\n", i - 1);
}

void Solve3() {
    int n, k;
    int a[N];
    int s[N];
    scanf("%d %d", &n, &k);
    const int remain = 60 * 4 - k;
    for1(i, n) a[i] = 5 * i;
    s[0] = 0;
    for1(i, n) s[i] = s[i-1] + a[i];

    int i = 0, j = n;
    assert(s[i] <= remain);
    if (s[i] == remain) {
        puts("0");
        return;
    }
    if (s[j] <= remain) {
        printf("%d\n", j);
        return;
    }

    // find index i let sum[i] > remain but sum[i-1] <= remain
    // s[i] < remain && s[j] > remain
    while (i <= j) {
        if (i == j) {  // move i first, so s[i] > remain
            break;
        }

        int h = (i + j) / 2;  // h maybe equal i, but can't be equal j
        if (s[h] <= remain) {
            i = h + 1;  // must move forward
        } else {
            j = h;  // must move forward
        }
    }

    printf("%d\n", i - 1);
}

void Solve2() {
    int n, k;
    scanf("%d %d", &n, &k);
    const int remain = 60 * 4 - k;
    int sum = 0;
    int ans = n;
    for1(i, n) {
        sum += 5 * i;
        if (sum > remain) {
            ans = i - 1;
            break;
        }
    }

    printf("%d\n", ans);
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
