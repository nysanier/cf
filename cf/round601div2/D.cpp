#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <limits>
#include <iostream>
#include <map>

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

int T;
int r, c;
int k;
char a[123][123];
char res[123][123];
int name[62];
int count[62];

/*
search like this(spin)
a ->     b
e ->    f|
^        |
|        V
d    <-  c

*/

int dir[4][2] = {
    {0, 1},  // same row, but column + 1
    {1, 0},  // same column, but row + 1
    {0, -1},  // same row, but column - 1
    {-1, 0},  // same column, but row - 1
};

void Case() {
    scanf("%d %d %d", &r, &c, &k);

    // init
    for (int i = 0; i < 10; ++i) {
        name[i] = '0' + i;
    }
    for (int i = 0; i < 26; ++i) {
        name[i + 10] = 'A' + i;
    }
    for (int i = 0; i < 26; ++i) {
        name[i + 10 + 26] = 'a' + i;
    }

    std::fill(count, count + k, 0);
    int n = r * c;
    while (n > 0) {
        for (int i = 0; i < k; ++i) {
            count[i] += 1;
            n -= 1;
            if (n == 0) {
                break;
            }
        }
    }

    // x is border
    std::fill(a[0], a[0] + c + 2, 'x');
    for (int i = 1; i <= r; ++i) {
        a[i][0] = 'x';
        scanf("%s", &a[i][1]);
        a[i][c+1] = 'x';
    }
    std::fill(a[r+1], a[r+1] + c + 2, 'x');

    int x = 1;
    int y = 1;
    int d = 0;
    int idx = 0;
    int dir_change_count = 0;
    int rice_count = 1;
    a[x][y] = 'x';
    res[x][y] = name[idx];
    for (;;) {
        int x2 = x + dir[d][0];
        int y2 = y + dir[d][1];
        if (a[x2][y2] == 'x') {
            d = (d + 1) % 4;  // next direction
            dir_change_count += 1;
            if (dir_change_count > 1) {
                break;  // final
            } else {
                continue;
            }
        }

        if (a[x2][y2] == '.') {
            a[x2][y2] = 'x';
            res[x][y] = name[idx];
            continue;
        }

        //  a[x2][y2] == 'R'
        if (rice_count > count[idx]) {
            rice_count = 0;
            idx += 1;
        }
        a[x2][y2] = 'x';
        res[x][y] = name[idx];
        rice_count += 1;
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            printf("%c", res[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // printf(">\n");
    scanf("%d", &T);
    while (T--) {
        Case();
    }

    return 0;
}
