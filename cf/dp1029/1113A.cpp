#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
    int n, v;
    scanf("%d %d", &n, &v);

    if (v == 1) {
        int sum = n * (n - 1) / 2;
        printf("%d\n", sum);
        return 0;
    }

    if (n - 1 <= v) {
        printf("%d\n", n - 1);
        return 0;
    }

    int sum = 0;
    int n2 = n - v;
    sum = (1 + n2) * n2 / 2 + (v - 1);
    printf("%d\n", sum);

    return 0;
}
