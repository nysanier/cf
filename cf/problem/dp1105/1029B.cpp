#include <stdio.h>
#include <stdint.h>
#include <string.h>
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

// f[i]: max lenth which contain a[i]
int f[200001];

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    f[0] = 1;
    for (int i = 1; i < n; ++i) {
        f[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (a[i] <= 2 * a[j]) {
                f[i] = f[j] + 1;
                break;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = std::max(ret, f[i]);
    }

    printf("%d\n", ret);

    return 0;
}
