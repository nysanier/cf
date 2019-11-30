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
struct Point {
    int l, r;
};
Point points[N];

void Case() {
    scanf("%d", &n);
    int most_left = 1e9;
    int most_left_idx = 0;
    int most_right = 0;
    int most_right_idx = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &points[i].l, &points[i].r);
        if (points[i].l < most_left) {
            most_left_idx = i;
            most_left = points[i].l;
        }

        if (points[i].r > most_right) {
            most_right_idx = i;
            most_right = points[i].r;
        }
    }

    int ans_left = points[most_left_idx].r;
    int ans_right = points[most_right_idx].l;
    for (int i = 0; i < n; ++i) {
        if (points[i].r < ans_left) {
            ans_left = points[i].r;
        }
        if (points[i].l > ans_right) {
            ans_right = points[i].l;
        }
    }

    // printf("%d %d\n", ans_left, ans_right);
    int ans = ans_right - ans_left;
    if (ans < 0) {
        ans = 0;
    }
    printf("%d\n", ans);
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
