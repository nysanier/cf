#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= decltype(x)(y); ++i)
#define foryx(i, x, y) for (auto i = y; i >= decltype(y)(x); --i)

using ll = long long;
using Vi = std::vector<int>;
using Vll = std::vector<ll>;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;
using Si = std::set<int>;
using Sll = std::set<ll>;

// -------------------------------------------------
const int N = 1e2 + 9;
int n;
ll k;
ll a[N];
 
void Solve() {
    scanf("%d %lld", &n, &k);
    a[1] = 1;
    forxy(i, 2, n) a[i] = 2 * a[i-1] + 1;
    int i = 0, j = n;
    while (i < j) {
        int h = (i + j) / 2;
        if (a[h] < k) {
            i = h + 1;
        } else {
            j = h;
        }
    }

    // i is the n
    while (i > 1) {
        // k is in the middle of a[i]
        if (k == a[i-1] + 1) {
            printf("%d\n", i);
            return;
        }
 
        // in the left
        if (k < a[i-1] + 1) {
            --i;
            continue;
        }
 
        // in the right
        // k > a[i-1] + 1
        k -= a[i-1] + 1;
        --i;
    }

    assert(i == 1 && k == 1);
    puts("1");
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
