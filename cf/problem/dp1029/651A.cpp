#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    int a1, a2;
    scanf("%d %d", &a1, &a2);
    if (a1 == 1 && a2 == 1) {
        printf("0\n");
        return 0;
    }

    int sum = 0;
    while (a1 > 0 && a2 > 0) {
        if (a1 > a2) {
            a1 -= 2;
            a2 += 1;
        } else {
            a2 -= 2;
            a1 += 1;
        }

        sum += 1;
    }

    printf("%d\n", sum);

    return 0;
}
