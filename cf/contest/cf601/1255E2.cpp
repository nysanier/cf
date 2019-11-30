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

const int N = 1e6 + 6;
int n;
int a[N];
int64_t S[N];

// return: the sum
int64_t ByK(int64_t k) {
    int64_t ret = 0;
    for (int i = 1; i < n; ++i) {
        ret += std::min(S[i] % k, k - S[i] % k);
    }

    return ret;
}

int main() {
    // printf(">\n");
    // std::cout << std::numeric_limits<int64_t>::max() << std::endl;
    // int64_t sum = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29 * 31 * 37; ~= 1e12
    // printf("sum = %d\n", sum);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    S[0] = 0;
    for (int i = 1; i <= n; ++i) {
        S[i] = a[i] + S[i-1];
    }

    if (S[n] < 2) {
        printf("-1\n");
        return 0;
    }

    // Decomposition prime
    int64_t min_res = 9 * 1e18;
    int64_t tmp = S[n];
    int64_t k = 2;
    for (; k * k <= tmp; ++k) {
        if (tmp % k == 0) {  
            min_res = std::min(min_res, ByK(k));
            while (tmp % k == 0) {  // remove all the factor k
                tmp /= k;
            }
        }
    }

    if (tmp > 1) {  // remain the last bigger prime!
        min_res = std::min(min_res, ByK(tmp));
    }

    std::cout << min_res << std::endl;

    return 0;
}
