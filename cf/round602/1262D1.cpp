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

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

int n;
int a[N];
int b[N];
std::multiset<int> mset;
int m;
int k, pos;

int main() {
    // printf(">\n");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = a[i];
    }

    std::sort(b, b + n);
    std::reverse(b, b + n);

    scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &k, &pos);
        mset.clear();
        int bi = 0;
        while (k--) {
            mset.insert(b[bi]);
            bi += 1;
        }

        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            auto it = mset.find(a[i]);
            if (it != mset.end()) {
                ans.push_back(a[i]);
                mset.erase(it);
            }
        }

        printf("%d\n", ans[pos-1]);
    }

    return 0;
}
