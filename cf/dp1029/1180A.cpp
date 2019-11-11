#include <stdio.h>
#include <algorithm>

int f[101];

int main() {
    // init
    f[1] = 1;
    for (int i = 2; i <= 100; ++i) {
        const int h = 2 * (i - 1) - 1;
        f[i] = f[i-1] + h + (h + 2);
    }

    int n;
    scanf("%d", &n);
    printf("%d\n", f[n]);


    return 0;
}
