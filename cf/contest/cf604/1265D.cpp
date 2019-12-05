#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)

using ll = long long;
using Vi = std::vector<int>;
using Vll = std::vector<ll>;
using Pii = std::pair<int, int>;
using Pll = std::pair<ll, ll>;
using Si = std::set<int>;
using Sll = std::set<ll>;

// -------------------------------------------------
const int N = 1e5 + 9;
int a, b, c, d;
int ans[N];

void Solve() {
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // no 0/1
    if (a == 0 && b == 0 && d - c == 1) {
        puts("YES");
        printf("3 ");
        for0(i, c) printf("2 3 ");
        puts("");
        return;
    }

    // no 2/3
    if (c == 0 && d == 0 && a - b == 1) {
        puts("YES");
        for0(i, b) printf("0 1 ");
        printf("0 ");
        puts("");
        return;
    }

    // patten must be: ?(1) 0 1 ... 0 1   2 1 ... 2 1   2 3 ... 2 3 ?(2)
    // len(1) >= len(0)
    // len(2) >= len(3)
    if (a > b || d > c) {
        puts("NO");
        return;
    }

    int b2 = b - a;
    int c2 = c - d;
    if (abs(b2 - c2) > 1) {
        puts("NO");
        return;
    }

    int p = 0;
    if (b2 > c2) {
        ans[p] = 1;
        ++p;
    }

    for0(i, a) {
        ans[p+2*i] = 0;
        ans[p+2*i+1] = 1;
    }
    p += 2*a;

    int m = std::min(b2, c2);
    for0(i, m) {
        ans[p+2*i] = 2;
        ans[p+2*i+1] = 1;
    }
    p += 2*m;

    for0(i, d) {
        ans[p+2*i] = 2;
        ans[p+2*i+1] = 3;
    }
    p += 2*d;
    if(c2 > b2) {
        ans[p] = 2;
        ++p;
    }
    
    puts("YES");
    for0(i, a+b+c+d) printf("%d ", ans[i]);
    puts("");
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
