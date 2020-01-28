#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 9 + 9;
int n;
string s[N];
string a[N];
// int vis[N][N];
set<char> row[N], col[N];
set<char> blk[N][N];
int R = 3, C = 3;
bool flag = false;
void Dfs(int i, int j) {
    DUMP(i, j);
    if (i == n) {
        flag = true;
        return;
    }
    int ni = i;
    int nj = j + 1;
    if (nj == n) {
        nj = 0;
        ni += 1;
    }
    DUMP(ni, nj);
    // 之前就是数字
    if (s[i][j] != '-') {
        DUMP(i, j, s[i][j]);
        Dfs(ni, nj);
        return;
    }

    for (char x = '1'; x <= '0'+n; ++x) {
        if (row[i].count(x) > 0) continue;
        if (col[j].count(x) > 0) continue;
        if (blk[i/R][j/C].count(x) > 0) continue;
        row[i].insert(x);
        col[j].insert(x);
        blk[i/R][j/C].insert(x);
        a[i][j] = x;
        DUMP(i, j, a[i][j]);
        Dfs(ni, nj);
        if (flag) return;
        a[i][j] = '-';
        blk[i/R][j/C].erase(x);
        col[j].erase(x);
        row[i].erase(x);
    }
}

}

void Init() {}
void Solve() {
    using namespace std;

    flag = false;
    for (int i = 0; i < N; ++i) {
        row[i].clear();
        col[i].clear();
        a[i].clear();
        s[i].clear();
        for (int j = 0; j < N; ++j) {
            blk[i][j].clear();
        }
    }
    std::cin >> n;
    assert(n == 4 || n == 6 || n == 9);
    if (n == 4) {
        R = C = 2;
    } else if (n == 9) {
        R = C = 3;
    } else {
        R = 2;
        C = 3;
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        assert(s[i].size() == n);
        a[i] = s[i];
        for (int j = 0; j < n; ++j) {
            if (s[i][j] >= '1' && s[i][j] <= '0'+n) {
                row[i].insert(s[i][j]);
                col[j].insert(s[i][j]);
                blk[i/R][j/C].insert(s[i][j]);
            }
        }
    }

    Dfs(0, 0);

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << std::endl;
    }
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Init();
    int t = 1;
    std::cin >> t;
    while (t--) Solve();

    return 0;
}
// 0,3, 456
