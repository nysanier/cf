// C
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

const int N = 1e2 + 9;
// std::cout << N << std::endl;

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

void Dump(const std::set<int>& set1) {
    for (auto v : set1) {
        printf("%d\n", v);
    }
}

int q;
int n;
int a[N];
int musk[N];

void Case() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    std::fill(musk, musk + n, 0);

    bool changed;
    do {
        changed = false;
        for (int i = n - 2; i >= 0; --i) {
            if (musk[i] == 0 && a[i] > a[i+1]) {
                changed = true;
                musk[i] = 1;
                std::swap(a[i], a[i+1]);
            }
        }
    } while (changed);

    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    // printf(">\n");
    scanf("%d", &q);
    while (q--) {
        Case();
    }

    return 0;
}
