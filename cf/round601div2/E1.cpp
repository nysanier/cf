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

int n;
int a[123456];

// int MinSum(int a, int b) {
//     std::vector<int> vec;
//     for (int i = a; i <= b; ++i) {
//         if (a[])
//     }
// }

int main() {
    // printf(">\n");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    if (sum <= 1) {
        printf("-1\n");
        return 0;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            continue;
        }

        a[i] -= 1;
        a[i+1] += 1;  // assert!
        res += 1;
    }

    printf("%d\n", res);

    return 0;
}
