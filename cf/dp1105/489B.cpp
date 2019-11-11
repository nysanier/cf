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
 
int main() {
    // printf("1234\n");
    int n;
    scanf("%d", &n);
    int boys[123];
    for (int i = 0; i < n; ++i) {
        scanf("%d", boys + i);
    }
    int m;
    scanf("%d", &m);
    int girls[123];
    for (int i = 0; i < m; ++i) {
        scanf("%d", girls + i);
    }

    std::sort(boys, boys + n);
    std::sort(girls, girls + m);
    int i = 0;
    int j = 0;
    int ret = 0;
    while (i < n && j < m) {
        int diff = boys[i] - girls[j];
        if (diff <= 1 && diff >= -1) {
            ret += 1;
            i += 1;
            j += 1;
        } else if (diff > 1) {
            j += 1;
        } else {
            i += 1;
        }
    }

    printf("%d\n", ret);

    return 0;
}
