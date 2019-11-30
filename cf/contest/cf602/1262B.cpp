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

const int N = 1e5 + 9;

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

int t;
int n;
int q[N];
std::set<int> setx;
int ans[N];

void Case() {
    scanf("%d", &n);
    setx.clear();
    for (int i = 0; i < n; ++i) {
        scanf("%d", q + i);
        setx.insert(i+1);
    }
    
    ans[0] = q[0];
    setx.erase(q[0]);
    int max_cur = ans[0];
    for (int i = 1; i < n; ++i) {
        if (q[i] > max_cur) {
            max_cur = q[i];
            ans[i] = q[i];
            setx.erase(q[i]);
        } else {
            auto it = setx.begin();
            if (*it < max_cur) {
                ans[i] = *it;
                setx.erase(it);
            } else {
                printf("-1\n");
                return;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
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
