#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>

std::vector<int> vec;

void f(int pre, int sum, int p) {
    // printf("f(%d, %d, %d)\n", pre, sum, p);
    assert(!(sum == 10 && p == 1));

    int i = 0;
    if (sum == 10) {
        i = 1;
    }

    if (p == 1) {
        int v = pre * 10 + sum;
        vec.push_back(v);
        return;
    }

    for (; i <= sum && i <= 9; ++i) {
        int v = pre * 10 + i;
        f(v, sum - i, p - 1);
    }
}

int main() {
    for (int p = 2; p <= 8; ++p) {
        f(0, 10, p);
    }

    // std::sort(vec.begin(), vec.end());
    // for (int i = 0; i < (int)vec.size(); ++i) {
    //     printf("[%d] %d\n", i, vec[i]);
    // }
    // printf("vec.size() = %d\n", (int)vec.size());

    int k;
    scanf("%d", &k);
    printf("%d\n", vec[k-1]);

    return 0;
}
