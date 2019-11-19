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
int n, m;
int a[1234];
int b[1234];

void Case() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    
    if (m < n || n == 2) {
        printf("-1\n");
        return;
    }

    std::copy(a, a + n, b);
    std::sort(a, a + n);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += 2 * a[i];
    }
    sum += (m - n) * (a[0] + a[1]);
    printf("%d\n", sum);
    for (int i = 1; i <= n; ++i) {
        int u = i;
        int v = i + 1;
        if (v > n) {
            v = 1;
        }
        printf("%d %d\n", u, v);
    }
    int u = -1;
    int v = -1;
    for (int i = 0; i < n; ++i) {
        if (u == -1 && b[i] == a[0]) {
            u = i + 1;
        }
        if (v == -1 && b[i] == a[1]) {
            v = i + 1;
            if (v == u) {  // can't be the same
                v = -1;
            }
        }
    }
    for (int i = 0; i < m - n; ++i) {
        printf("%d %d\n", u, v);
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
