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
    printf("------- dump -------\n");
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

int n, B;
std::vector<int> a;
std::vector<int> f;
std::vector<int> g;

int main() {
    scanf("%d %d", &n, &B);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int sum_odd = 0;
    int sum_even = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] % 2 == 0) {
            sum_even += 1;
        } else {
            sum_odd += 1;
        }

        if (sum_even == sum_odd) {
            f.push_back(i);
        }
    }

    if (f.empty()) {
        // printf("f.empty()\n");
        printf("0\n");
        return 0;
    }

    // Dump(f);
    for (int i = 0; i < (int)f.size(); ++i) {
        int d = a[f[i]] - a[f[i]+1];
        if (d < 0) d = -d;
        if (d <= B)
            g.push_back(d);
    }

    if (g.empty()) {
        // printf("g.empty()\n");
        printf("0\n");
        return 0;
    }

    // Dump(g);
    std::sort(g.begin(), g.end());
    // Dump(g);
    int sum = 0;
    int ret = 0;
    for (auto it = g.begin(); it != g.end() && sum <= B; ++it) {
        if (sum + *it <= B) {
            sum += *it;
            ret += 1;
        }
    }

    printf("%d\n", ret);

    return 0;
}
