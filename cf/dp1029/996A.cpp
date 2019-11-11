#include <stdio.h>
#include <algorithm>

int p[] = {1, 5, 10, 20, 100};

int main() {
    int n;
    scanf("%d", &n);
    int s = 0;
    size_t size = sizeof(p) / sizeof(p[0]);
    // printf("size=%d\n", (int)size);
    for (int i = (int)size - 1; i >= 0; --i) {
        int v = n / p[i];
        n -= v * p[i];
        s += v;
        // printf("p[%d]=%d, v=%d, n=%d, s=%d\n", i, p[i], v, n, s);
    }

    printf("%d\n", s);


    return 0;
}
