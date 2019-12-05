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
const int N = 2e5 + 9;
int n;
int a[N];

void Solve() {
    scanf("%d", &n);
    std::map<int, int> mapx;
    for1(i, n) {
        scanf("%d", a + i);
        mapx[a[i]] = i;
    }
    assert(mapx.size() == n);

    std::string ans;
    ans.resize(n);
    int m1 = mapx[1];  // min
    int m2 = m1;  // max
    ans[0] = '1';
    forxy(i, 2, n) {
        int x = mapx[i];
        m1 = std::min(m1, x);
        m2 = std::max(m2, x);
        // printf("i(%d), m1(%d), m2(%d)\n", i, m1, m2);
        int len = m2 - m1 + 1;
        if (len == i) {
            ans[i-1] = '1';
        } else {
            ans[i-1] = '0';
        }
    }

    printf("%s\n", ans.c_str());
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
