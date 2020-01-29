#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "dump.h"

// -------------------------------------------------
namespace {
using namespace std;

const int N = 9 + 9;
int n;  // 方阵边长
string s[N];  // 原始数据
string a[N];  // 处理结果
set<char> row[N], col[N];  // 行列去重
set<char> blk[N][N];  // 方块去重
int R, C;  // 方块的行列边长
bool flag;  // 是否已经找到解
const char B = '-';  // 空字符，就需要填空的位置

// 回溯法找解, 从上到下，从左到右，枚举每个空可以填的值
void Dfs(int i, int j) {
    // 是否已经填完所有空
    // DUMP(i, j);
    if (i == n) {
        flag = true;
        return;
    }

    // 当前位置的下一个位置
    int ni = i;
    int nj = j + 1;
    if (nj == n) {
        nj = 0;
        ni += 1;
    }

    // 当前位置不需要填空
    // DUMP(ni, nj);
    // 之前就是数字
    if (s[i][j] != B) {
        // DUMP(i, j, s[i][j]);
        Dfs(ni, nj);
        return;
    }

    // 暴力枚举
    for (char x = '1'; x <= '0'+n; ++x) {
        if (row[i].count(x) > 0) continue;
        if (col[j].count(x) > 0) continue;
        if (blk[i/R][j/C].count(x) > 0) continue;
        row[i].insert(x);
        col[j].insert(x);
        blk[i/R][j/C].insert(x);
        a[i][j] = x;
        // DUMP(i, j, a[i][j]);
        Dfs(ni, nj);
        if (flag) return;
        a[i][j] = B;
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
    // 如何风格方块
    assert(n == 4 || n == 6 || n == 9);
    if (n == 4) {
        R = C = 2;
    } else if (n == 9) {
        R = C = 3;
    } else {
        R = 2;
        C = 3;
    }
    // 预处理:
    //   校验输入（assert）
    //   行/列/方块提前设置限制（剪枝）
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        assert(s[i].size() == n);
        a[i] = s[i];
        for (int j = 0; j < n; ++j) {
            // 必须是空字符（-），或者是1-n的数字
            if (!isdigit(s[i][j])) {
                assert(s[i][j] == B);
                continue;
            }
            assert(s[i][j] >= '1');
            assert(s[i][j] <= '0'+n);
            row[i].insert(s[i][j]);
            col[j].insert(s[i][j]);
            blk[i/R][j/C].insert(s[i][j]);
        }
    }

    // 回溯填空
    Dfs(0, 0);

    // 输出结果
    for (int i = 0; i < n; ++i) {
        // 每隔C列，打印空列
        std::string str;
        for (int j = 0; j < n; ++j) {
            str.append(1, a[i][j]);
            if (j != n-1 && (j+1) % C == 0) str.append(1, ' ');
        }
        std::cout << str << std::endl;
        // 每隔R行，打印空行
        if (i != n-1 && (i+1) % R == 0) {
            std::cout << std::endl;
        }
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

/*
输入解释：
一个数字n，表示方阵的边长。
然后n行字符串，数字表示已经填好的值，-表示需要填的空，不能有其他字符

input.txt:
1

9
---------
---------
---------
---------
---------
---------
---------
---------
---------

4
----
----
----
----

6
------
------
------
------
------
------

4
----
3-4-
--3-
---2

9
-------7-
-6-4-72-8
--382-5--
4-27--6--
---------
--1--84-5
--6-849--
2-46-1-5-
-3-------


9
------39-
8---4-51-
-9-8----2
78--9----
--9-2-8--
----1--25
9----4-6-
-27-3---9
-41------




9
19-2----3
--83--61-
-631----4
-31--2---
---------
---5--16-
3----928-
-15--74--
6----1-37



*/
