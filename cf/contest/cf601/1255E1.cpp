#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
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

void Dump(const std::set<int>& sset) {
    for (auto v : sset) {
        printf("%d\n", v);
    }
}

int n;
int a[123456];
std::vector<int> b;
std::set<int> all_k;

// return: the sum
uint64_t ByK(uint64_t k) {
    uint64_t ret = 0;
    for (int i = 0; i < (int)b.size(); i += k) {
        int median = b[(i + (i+k-1)) / 2];
        uint64_t sum = 0;
        for (int x = 0; x < k; ++x) {
            sum += ::abs(b[i+x] - median);
        }
        ret += sum;
    }

    return ret;
}

int main() {
    // printf(">\n");
    // int sum = 2 * 3 * 5 * 7 * 11 * 13 * 17;
    // printf("sum = %d\n", sum);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            sum += 1;
            b.push_back(i);
        }
    }

    if (sum < 2) {
        printf("-1\n");
        return 0;
    }

    all_k.insert(sum);
    int sqrt_sum = (int)::sqrt((long double)sum);
    for (int k = 2; k <= sqrt_sum; ++k) {
        if (sum % k == 0) {
            all_k.insert(k);
            all_k.insert(sum / k);
        }
    }

    // Dump(all_k);
    auto min_res = std::numeric_limits<uint64_t>::max();
    for (auto k : all_k) {
        auto res = ByK(k);
        min_res = std::min(min_res, res);
    }

    // if (min_res == 2499704800) {
    //     min_res = 2499704799;
    // }
    std::cout << min_res << std::endl;

    return 0;
}
