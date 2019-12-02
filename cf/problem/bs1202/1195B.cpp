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

int n, k;

// let x be take the option to put, so n-x eat
// x^2 + 3x + -2(n+k) = 0
// x = (-b+-sqrt(b^2-4ac)) / 2a
// x = (-3+sqrt(9+8(n+k))/2
void Solve() {
    scanf("%d %d", &n, &k);
    ll sq = sqrt(9+8ll*(n+k));
    assert(sq * sq == 9+8ll*(n+k));
    ll x = (-3+sq)/2;
    ll ans = n - x;
    printf("%lld\n", ans);
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
