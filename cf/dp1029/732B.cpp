#include <stdio.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>

int walk(int n, int k, std::vector<int>& a) {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        int v = k - a[i] - a[i-1];
        if (v > 0) {
            a[i] += v;
            ret += v;
        }
    }

    return ret;
}

// (A1+A2) + ... + (An-1+An) >= (n-1) * k
// x >= ((n-1)*k+A1+An)/2 - sigma(ai)
int main() {
    std::vector<int> a;
    int n, k;
    scanf("%d %d", &n, &k);
    a.resize(n + 1);
    a[0] = k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    int ret = walk(n, k, a);
    printf("%d\n", ret);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // int s = (n - 1) * k + a[1] + a[n];
    // if (s % 2 == 1) {
    //     s += 1;
    // }

    // int x = s / 2;
    // for (int i = 1; i <= n; ++i) {
    //     x -= a[i];
    // }

    // if (x < 0)
    //     x = 0;
    // printf("%d\n", x);

    return 0;
}
