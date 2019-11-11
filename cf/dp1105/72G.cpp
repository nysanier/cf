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

int f[22];
 
int main() {
    // printf("1234\n");
    
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i < 20; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    // Dump(f, 20);

    int n;
    scanf("%d", &n);
    printf("%d\n", f[n]);

    return 0;
}
