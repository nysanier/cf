#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <limits>

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        printf("[%d] %d\n", i, vec[i]);
    }
}

std::vector<int> vec;
int Sum1(int i, int j) {
    int sum = 0;
    for (int x = i; x < j;  ++x) {
        if (vec[x] == 1) {
            sum += 1;
        }
    }

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < (int)vec.size(); ++i) {
        scanf("%d", &vec[i]);
    }

    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int v1 = Sum1(0, i);
            int v2 = (j + 1 - i) - Sum1(i, j + 1);
            int v3 = Sum1(j + 1, n);
            max_val = std::max(max_val, v1 + v2 + v3);
        }
    }

    printf("%d\n", max_val);

    return 0;
}
