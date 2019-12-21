#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 != 0) {
        printf("0\n");
        return 0;
    }

    printf("%d\n", 1 << (n / 2));

    return 0;
}
