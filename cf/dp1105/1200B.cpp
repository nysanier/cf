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
 
void Dump(const int a[], int sz) {
    for (int i = 0; i < sz; ++i) {
        printf("%d\n", a[i]);
    }
}

int t;
int n, m, k;
int a[123];

void Case() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            printf("YES\n");
            return;
        }

        if (a[i] + k < a[i+1]) {
            if (a[i] + k + m < a[i+1]) {
                printf("NO\n");
                return;
            }

            m -= a[i+1] - a[i] - k;
        } else {
            int d = a[i] + k - a[i+1];
            if (d > a[i])
                d = a[i];
            m += d;
        }
    }

    assert(0);
}

int main() {
    // printf(">> \n");
    scanf("%d", &t);
    while (t--) {
        Case();
    }

    return 0;
}
