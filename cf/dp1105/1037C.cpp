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
 
void Dump(const int a[], int sz) {
    for (int i = 0; i < sz; ++i) {
        printf("%d\n", a[i]);
    }
}

int n;
char a[1234567];
char b[1234567];

int main() {
    int n;
    scanf("%d %s %s", &n, a, b);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            continue;
        }

        if (i == n - 1) {
            res += 1;
            break;
        }

        // can execute swap
        if (a[i] == b[i+1] && a[i+1] == b[i]) {
            res += 1;
            i += 1;  // skip a[i+1]
            continue;
        }

        // flip
        res += 1;
    }

    printf("%d\n", res);

    return 0;
}
