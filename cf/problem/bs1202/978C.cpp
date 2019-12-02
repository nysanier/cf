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
const int N = 2e5 + 9;

int n, m;
ll a[N];
ll s[N];
ll b;

void Solve() {
    scanf("%d %d", &n, &m);
    for1(i, n) scanf("%lld", a + i);
    s[0] = 0;
    for1(i, n) s[i] = s[i-1] + a[i];

    int p = 1;
    for0(i, m) {
        scanf("%lld", &b);
        for (; p <= n; ++p) {
            if (s[p] >= b && s[p-1] < b) {
                break;
            }
        }
        int f = p;
        ll k = b - s[p-1];
        // printf("p=%d, s[%d]=%lld\n", p, p, s[p]);
        printf("%d %lld\n", f, k);
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
