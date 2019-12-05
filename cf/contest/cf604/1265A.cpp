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
char s[N];

char Next(char c) {
    if (c == 'c')
        return 'a';
    return c + 1;
}

char Get(char x, char y) {
    if (x == '?' || y == '?') {
        if (x == '?' && y == '?')
            return 'a';
        if (y == '?')
            std::swap(x, y);
        return Next(y);
    }

    if (x == y)
        return Next(x);
    if (x > y)
        std::swap(x, y);
    if (x == 'a' && y == 'b')
        return 'c';
    if (x == 'a' && y == 'c')
        return 'b';
    if (x == 'b' && y == 'c')
        return 'a';

    assert(0);
    return 'X';
}

void Solve() {
    scanf("%s", s);
    std::string str(s);
    int n = str.size();
    if (n == 1u) {
        if (str[0] == '?') {
            str[0] = Get('?', '?');
        }
        printf("%s\n", str.c_str());
        return;
    }

    if (str[0] == '?') {
        str[0] = Get('?', str[1]);
    }

    if (str[n-1] == '?') {
        str[n-1] = Get(str[n-2], '?');
    }

    forxy(i, 1, n-2) {
        if (str[i] == '?')
            str[i] = Get(str[i-1], str[i+1]);
    }

    auto it = std::unique(str.begin(), str.end());
    if (it != str.end()) {
        puts("-1");
    } else {
        printf("%s\n", str.c_str());
    }

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
