#include "bits/stdc++.h"

int t;

void Case() {
    int a[3];
    scanf("%d %d %d", a+0, a+1, a+2);
    std::sort(a, a + 3);

    int d = a[2] - a[1];
    if (d > a[0]) {
        printf("%d\n", a[0] + a[1]);
        return;
    }

    int sum = d;
    a[0] -= d;
    a[2] -= d;
    int d2 = a[0] / 2;
    sum += d2 * 2 + (a[1] - d2);
    printf("%d\n", sum);


    // int sum = a[2] - a[1];
    // a[2] -= a[0];
    // if (a[1] < a[2]) {
    //     sum += a[1];
    // } else {
    //     sum += a[2];
    // }

    // printf("%d\n", sum);
}

int main() {
    // printf(">\n");
    int t;
    scanf("%d", &t);
    while (t--) {
        Case();
    }

    return 0;
}
