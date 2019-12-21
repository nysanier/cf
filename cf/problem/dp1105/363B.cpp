#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <limits>
#include <map>
#include <string.h>

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

int f[150000];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }

    f[0] = Sum(k);
    int idx = 0;
    int ret = f[0];
    for (int r = 1; r < n-k+1; ++r) {
        f[r] = f[r-1] - vec[r-1] + vec[r+k-1];
        if (f[r] < ret) {
            idx = r;
            ret = f[r];
        }
    }

    printf("%d\n", idx+1);

    return 0;
}
