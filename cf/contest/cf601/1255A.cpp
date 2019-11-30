#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <limits>
#include <iostream>
#include <map>

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

int T;
int a, b;

void Case() {
    scanf("%d %d", &a, &b);
    int c = a - b;
    if (c < 0) {
        c = -c;
    }

    int sum = 0;
    if (c >= 5) {
        int d = c / 5;
        sum += d;
        c -= d * 5;
    }

    if (c >= 2) {
        int d = c / 2;
        sum += d;
        c -= d * 2;
    }

    sum += c;
    printf("%d\n", sum);
}

int main() {
    // printf(">\n");
    scanf("%d", &T);
    while (T--) {
        Case();
    }

    return 0;
}
