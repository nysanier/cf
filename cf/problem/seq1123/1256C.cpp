// C
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

const int N = 1e3 + 9;

int n, m, d;
int c[N];
int res[N];

int main() {
    // printf(">\n");
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", c + i);
    }

    int max_space_once = d - 1;
    int sum_wood = 0;
    for (int i = 1; i <= m; ++i) {
        sum_wood += c[i];
    }

    int max_space = (m + 1) * max_space_once;
    if (max_space + sum_wood < n) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    int left_space = n - sum_wood;
    int k = 1;
    int idx = 1;
    for (int i = 1; i <= m; ++i) {
        // fill 0
        if (left_space > 0) {
            int space_cur = max_space_once;
            if (space_cur > left_space) {
                space_cur = left_space;
            }
            left_space -= space_cur;
            std::fill(res + k, res + k + space_cur, 0);
            k += space_cur;
        }

        // fill idx
        std::fill(res + k, res + k + c[i], idx);
        idx += 1;
        k += c[i];
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
