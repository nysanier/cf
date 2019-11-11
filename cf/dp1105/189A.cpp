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
 
int main() {
    // printf("1234\n");
    int n, a[3];
    scanf("%d %d %d %d", &n, a, a+1, a+2);
    std::sort(a, a + 3);
    // int X = n / a[0];
    int Y = n / a[1];
    int Z = n / a[2];
    int max_ret = 0;
    for (int zz = 0; zz <= Z; ++zz) {
        for (int yy = 0; yy <= Y; ++yy) {
            auto n2 = n - zz * a[2] - yy * a[1];
            if (n2 < 0) {
                continue;
            }

            if (n2 % a[0] == 0) {
                int xx = n2 / a[0];
                int ret = xx + yy + zz;
                max_ret = std::max(max_ret, ret);
                // printf("%d\n", ret);
                // printf("%d = %d + %d + %d\n", max_ret, xx, yy, zz);
                // return 0;
            }
        }
    }
 
    printf("%d\n", max_ret);
    // assert(0);
    return 0;
}
