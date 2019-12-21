#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stdint.h>

int main() {
    std::vector<long> vec;
    int n;
    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &vec[i]);
    }

    int negative = 0;
    uint64_t ret = 0;
    bool has_zero = false;
    for (int i = 0; i < n; ++i) {
        if (vec[i] > 0) {
            ret += vec[i] - 1;
        } else if (vec[i] < 0) {
            negative += 1;
            ret += -1 - vec[i];
        } else {  // 0
            has_zero = true;
            ret += 1;
        }
    }

    if (negative % 2 == 1 && !has_zero) {
        ret += 2;
    }
    std::cout << ret << std::endl;

    return 0;
}
