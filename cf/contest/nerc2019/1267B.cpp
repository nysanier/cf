#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
const int N = 3e5 + 9;

int n;
char s[N];

void Solve() {
    scanf("%s", s);
    int i = 0;
    int j = (int)strlen(s) - 1;
    if (i == j) {
        puts("0");
        return;
    }

    char ch;
    while (i <= j) {
        ch = s[i];
        if (s[j] != ch) {
            puts("0");
            return;
        }

        int p = i + 1;
        while (p <= j && s[p] == ch)
            ++p;
        if (p > j) {  // over
            // printf("");
            int l = p - i;
            if (l < 2) {
                puts("0");
                return;
            }

            printf("%d\n", l + 1);  // l or r or mid
            return;
        }

        int k = j;
        while (k > p && s[k] == ch)
            --k;

        // check
        int len1 = p - i;
        int len2 = j - k;
        if (len1 + len2 < 3) {
            puts("0");
            return;
        }

        // next
        i = p;
        j = k;
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
