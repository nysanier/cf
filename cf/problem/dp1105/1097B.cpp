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

int n;
std::vector<int> vec;
bool Search(int k, int sum) {
    // printf("test k=%d, sum=%d\n", k, sum);
    if (k == n) {
        if (sum % 360 == 0) {
            // printf("over\n");
            return true;
        } else {
            // printf("failed\n");
            return false;
        }
    }

    int a[2];
    a[0] = vec[k];
    a[1] = -vec[k];
    for (int i = 0; i < 2; ++i) {
        auto ret = Search(k + 1, sum + a[i]);
        if (ret) {
            return true;
        }
    }

    return false;
}

int main() {
    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }

    auto ret = Search(0, 0);
    if (ret) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
