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

const int N = 2e3 + 9;

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

int t;
int n, k;
char s[N];
char s2[N];
std::vector<std::pair<int, int>> vec;

int Find(int i, char ch) {
    // printf("Find i=%d, ch=%c\n", i, ch);
    for (; i < n; ++i) {
        if (s[i] == ch) {
            return i;
        }
    }

    assert(0);
    return n;
}

void Reverse(int i, int j) {
    // int p = 0;
    // while (i+p < j-p) {

    // }
    std::reverse(s + i, s + j + 1);
}

void Case() {
    scanf("%d %d", &n, &k);
    vec.clear();
    scanf("%s", s);
    {
        int k1 = k - 1;
        for (int i = 0; i < k1 * 2; i += 2) {
            s2[i] = '(';
            s2[i+1] = ')';
        }

        for (int i = 0; i < n/2-k1; ++i) {
            s2[2*k1+i] = '(';
        }
        for (int i = 0; i < n/2-k1; ++i) {
            s2[2*k1+(n/2-k1)+i] = ')';
        }
        s2[n] = '\0';
    }

    // printf("s2 = '%s'\n", s2);
    // printf("s1 = '%s'\n", s);

    for (int i = 0; i < n; ++i) {
        if (s[i] == s2[i]) {
            continue;
        }

        auto x = Find(i+1, s2[i]);
        Reverse(i, x);
        // printf("s2 = ''");
        // printf("s1 = '%s'\n", s);
        vec.push_back(std::make_pair(i+1, x+1));
    }

    printf("%d\n", (int)vec.size());
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        printf("%d %d\n", it->first, it->second);
    }
}

int main() {
    // printf(">\n");
    scanf("%d", &t);
    while (t--) {
        Case();
    }

    // std::cout << N << std::endl;
    return 0;
}
