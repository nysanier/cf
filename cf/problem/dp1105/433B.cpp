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

std::vector<int> vec;
int Sum(int k) {
    int sum = 0;
    for (int x = 0; x < k; ++x) {
        sum += vec[x];
    }

    return sum;
}

// f(i) = sum from 1 to i
int64_t f1[100000];
int64_t f2[100000];

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> vec1;
    vec1.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec1[i]);
    }

    std::vector<int> vec2(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());
    f2[0] = vec2[0];
    for (int i = 1; i < (int)vec2.size(); ++i) {
        f2[i] = f2[i-1] + vec2[i];
    }

    f1[0] = vec1[0];
    for (int i = 1; i < (int)vec1.size(); ++i) {
        f1[i] = f1[i-1] + vec1[i];
    }

    int m;
    scanf("%d", &m);
    int t, l, r;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &t, &l, &r);
        int64_t ret;
        if (t == 1) {
            ret = f1[r-1] - f1[l-1] + vec1[l-1];
        } else {
            ret = f2[r-1] - f2[l-1] + vec2[l-1];
        }
        std::cout << ret << std::endl;
    }

    return 0;
}
