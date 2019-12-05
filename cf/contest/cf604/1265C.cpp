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
const int N = 4e5 + 9;
int n;
int a[N];

void Solve() {
    std::map<int, int> mapx;
    scanf("%d", &n);
    for0(i, n) {
        scanf("%d", a + i);
        mapx[-a[i]] += 1;
    }

    if (n <= 5) {  // g >= 1, s >= 2, b >= 2
        // printf("debug n <= 5\n");
        puts("0 0 0");
        return;
    }

    int mid = n / 2 - 1;
    int m1 = a[mid]; // >= m1
    if (a[mid] == a[mid+1]) {  // so much metals, so no a[mid]
        m1 = a[mid] + 1;
    }

    // printf("debug m1 = %d\n", m1);

    int sum = 0;
    std::map<int, int> map2;
    for (auto& kv : mapx) {
        if (-kv.first >= m1) {
            // printf("debug add %d-%d\n", -kv.first, kv.second);
            map2[kv.first] = kv.second;
            sum += kv.second;
        } else {
            break;
        }
    }

    if (map2.size() < 3u) {
        // printf("debug map2.size = %d\n", (int)map2.size());
        puts("0 0 0");
        return;
    }

    auto it2 = map2.begin();
    int g = it2->second;
    ++it2;
    int s = 0;
    int b = 0;
    for (; it2 != map2.end(); ++it2) {
        int v = it2->second;
        if (s <= g) {
            s += v;
        } else {
            b += v;
        }
    }
    // printf("debug %d %d %d\n", g, s, b);
    if (g >= s || g >= b || b == 0 || s == 0) {
        puts("0 0 0");
        return;
    }

    printf("%d %d %d\n", g, s, b);

    // for0r(i, n) printf("%d\n", a[i]);
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
