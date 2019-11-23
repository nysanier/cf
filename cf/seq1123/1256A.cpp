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


void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

void Dump(const std::set<int>& sset) {
    for (auto v : sset) {
        printf("%d\n", v);
    }
}

// const int N = 1e6 + 9;
// std::cout << N << std::endl;
int q;
int a, b, n, S;

void Case() {
    scanf("%d %d %d %d", &a, &b, &n, &S);
    if (int64_t(a) * n + b < S) {
        printf("NO\n");
        return;
    }

    if (S - int64_t(S) / n * n > b) {
        printf("NO\n");
        return;
    }

    printf("YES\n");
}

int main() {
    // printf(">\n");
    scanf("%d", &q);
    while (q--) {
        Case();
    }

    return 0;
}
