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
int a[523456];
// b[0] : num of 4
// b[1] : num of 8
// ...
// related by mm
// make sure b[i] >= b[i+1]
int b[6] = {0, 0, 0, 0, 0, 0};
int res = 0;
std::map<int, int> mm = {
    {4, 0},
    {8, 1},
    {15, 2},
    {16, 3},
    {23, 4},
    {42, 5},
};

int main() {
    // printf(">> \n");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; ++i) {
        auto v = mm[a[i]];
        if (v == 0) {
            b[0] += 1;
        } else {
            if (b[v-1] > b[v]) {
                b[v] += 1;
            } else { // drop it
                res += 1;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        res += b[i] - b[5];
    }

    printf("%d\n", res);

    return 0;
}
