#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
const int N = 1e3 + 9;

int n, l, k;
char s[N*N];

void Solve() {
    scanf("%d %d %d", &n, &l, &k);
    scanf("%s", s);
    std::sort(s, s + n * l);
    int idx = 0;
    std::vector<std::string> ans(n);
    int i = 0;
    int j = k - 1;
    int sum = 0;
    while (i < j) {
        char ch = s[idx + j - i];  // the kth char
        // printf("choose ch = '%c', when j = %d\n", ch, j);
        int i2 = i - 1;
        for (int p = i; p <= j; ++p) {
            if (s[idx] < ch) {
                i2 = p;
            }
            ans[p].push_back(s[idx]);
            // printf("<1> %d] insert %c\n", p, s[idx]);
            ++idx;
        }

        i = i2 + 1;
        // printf("change i to %d\n", i);

        ++sum;
        if (sum == l) {
            break;
        }
    }

    // fill kth
    int d = l - ans[k-1].size();
    while (d--) {
        ans[k-1].push_back(s[idx]);
        // printf("<2> %d] insert %c\n", k-1, s[idx]);
        ++idx;
    }

    // fill others
    for (int p = 0; p < n; ++p) {
        int d = l - ans[p].size();
        while (d--) {
            ans[p].push_back(s[idx]);
            // printf("<2> %d] insert %c\n", p, s[idx]);
            ++idx;
        }
    }

    for (int p = 0; p < n; ++p) {
        printf("%s\n", ans[p].c_str());
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
