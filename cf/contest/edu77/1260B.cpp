#include <bits/stdc++.h>

int t;

void Case() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (;;) {
        if (a == b) {
            if (a == 0) {
                puts("YES");
                return;
            }

            if (a == 1 || a == 2) {
                puts("NO");
                return;
            }

            int x = a / 3;
            a -= 3 * x;
            b -= 3 * x;
            continue;
        }

        // a != b
        if (a > b) {
            std::swap(a, b);
        }
        if (a == 0) {
            puts("NO");
            return;
        }

        int d = b - a;
        if (d > a) {
            d = a;
        }

        a -= d;
        b -= 2 * d;
    }
}

int main() {
    // printf(">\n");
    scanf("%d", &t);
    while (t--) {
        Case();
    }

    return 0;
}
