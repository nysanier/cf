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

int n, k;
int a[123456];
int t[123456];
int sum[123456];  // sum[i] accumulate [0, i]
int suma[123456];  // suma[i] ignore t
int sumk[123456];  // sumk[i] accumulte [i-k+1, i], help by suma

int main() {
    // printf(">> \n");
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", t + i);
    }

    sum[0] = a[0] * t[0];
    suma[0] = a[0];
    sumk[0] = a[0];
    // printf("%5s] %10s %10s %10s\n", "idx", "sum", "suma", "sumk");
    // printf("%5d] %10d %10d %10d\n", 0, sum[0], suma[0], sumk[0]);
    for (int i = 1; i < n; ++i) {
        sum[i] = a[i] * t[i] + sum[i-1];
        suma[i] = a[i] + suma[i-1];
        if (i < k) {
            sumk[i] = suma[i];
        } else {
            sumk[i] = suma[i] - suma[i-k];
        }
        // printf("%5d] %10d %10d %10d\n", i, sum[i], suma[i], sumk[i]);
    }

    int max_res = 0;
    for (int i = k - 1; i < n; ++i) {
        int sum_left = 0;
        if (i >= k) {
            sum_left = sum[i-k];
        }
        int sum_right = sum[n-1] - sum[i];
        int v = sum_left + sumk[i] + sum_right;
        max_res = std::max(max_res, v);
    }

    printf("%d\n", max_res);

    return 0;
}
