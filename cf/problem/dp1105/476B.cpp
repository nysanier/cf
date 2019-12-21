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

std::map<int, int> mm;
int total = 0;
char s1[12];
char s2[12];

void f(int k, int len, int sum) {
    if (k == len) {
        mm[sum] += 1;
        total += 1;
        return;
    }

    switch (s2[k]) {
    case '+':
        f(k + 1, len, sum + 1);
        break;
    case '-':
        f(k + 1, len, sum - 1);
        break;
    case '?':
        f(k + 1, len, sum + 1);
        f(k + 1, len, sum - 1);
        break;
    default:
        assert(0);
    }
}

int main() {
    scanf("%s %s", s1, s2);
    int sum = 0;
    for (auto p = s1; *p != '\0'; p ++) {
        if (*p == '+') {
            sum += 1;
        } else if (*p == '-') {
            sum -= 1;
        } else {
            assert(0);
        }
    }

    int len = strlen(s2);
    f(0, len, 0);
    auto res = double(mm[sum]) / total;
    printf("%.12lf\n", res);


    return 0;
}
