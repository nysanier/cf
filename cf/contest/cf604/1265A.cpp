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

char Get(char x, char y) {
    if (x == y) {
        if (x == 'c') {
            return 'a';
        } else {
            return x + 1;
        }
    }

    if (x > y) {
        std::swap(x, y);
    }

    if (x == 'a' && y == 'b') {
        return 'c';
    }

    if (x == 'a' && y == 'c') {
        return 'b';
    }

    if (x == 'b' && y == 'c') {
        return 'a';
    }

    assert(0);
    return 'X';
}

void Solve() {
    scanf("%s", s);
    std::string str(s);
    while (true) {
        auto p1 = str.find_first_of('?');
        if (p1 == str.npos) {
            break;
        }
        char x;
        if (p1 == 0u) {
            x = 'a';  // subian
        } else {
            x = str[p1-1];
        }
        int y;
        auto p2 = str.find_first_not_of('?', p1);
        if (p2 == str.npos) {
            p2 = str.size();
            y = 'b';  // suibian
        } else {
            y = str[p2];
        }

        std::string re;
        int len = p2 - p1;
        if (len % 2 == 0) {
            // puts("% 2 == 0");
            re.resize(2);
            re[1] = Get(x, y);
            re[0] = Get(x, re[1]);
        } else {
            // puts("% 2 == 1");
            re.resize(2);
            re[0] = Get(x, y);
            re[1] = Get(x, re[0]);
        }
        // printf("re = '%s'\n", re.c_str());

        int j = 0;
        for (auto i = p1; i < p2; ++i, j = (j + 1) % 2) {
            str[i] = re[j];
        }
    }

    // printf("%s\n", str.c_str());
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
