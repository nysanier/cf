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

int n;
int64_t f[1234567];

int64_t MaxDigit(int64_t a) {
    if (a < 10) {
        return a;
    }

    int64_t ret = 0;
    while (a > 0) {
        ret = std::max(ret, a % 10);
        a /= 10;
    }
    return ret;
}

int main() {
    // printf(">> \n");
    scanf("%d", &n);
    std::fill(f, f + n, -1);
    f[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (i < 10) {
            f[i] = 1;
            // printf("%3d] 1\n", i);
            continue;
        }

        int sum = 0;
        int v = i;
        // printf("%3d] ", i);
        while (v > 0) {
            auto cur_max = (int)MaxDigit(v);
            v -= cur_max;
            sum += 1;
            // printf(", -%d", cur_max);
            if (f[v] != -1) {
                sum += f[v];
                // printf(", take f[%d]", v);
                v = 0;
            }
        }
        f[i] = sum;
    
        // printf(" %ld\n", (long)f[i]);
    }

    printf("%ld\n", (long)f[n]);

    return 0;
}
