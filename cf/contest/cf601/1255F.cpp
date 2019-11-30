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

const int N = 1e3 + 9;
using ll = long long;

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

// std::cout << N << std::endl;
int n;
std::vector<int> left, right;
ll area12[N];

ll GetArea(int i, int j, int k) {
    printf("1 %d %d %d\n", i, j, k);
    fflush(stdout);
    ll area;
    scanf("%lld", &area);
    return area;
}

int GetSign(int i, int j, int k) {
    printf("2 %d %d %d\n", i, j, k);
    fflush(stdout);
    int sign = 0;
    scanf("%d", &sign);
    // assert(sign == 1 || sign == -1);
    if (sign != 1 && sign != -1) {
        printf("sign = %d\n", sign);
        assert(0);
    }
    return sign;
}

void Divide() {
    for (int i = 3; i <= n; ++i) {
        auto sign = GetSign(1, 2, i);
        if (sign > 0)
            left.push_back(i);
        else {
            right.push_back(i);
        }
    }
    area12[1] = 0;
    area12[2] = 0;
}

void Sort(std::vector<int>& vec) {
    if (vec.empty())
        return;

    int farest = 1;
    for (auto v : vec) {
        area12[v] = GetArea(1, 2, v);
        if (area12[v] > area12[farest]) {
            farest = v;
        }
    }

    // divide again by farest vertex
    std::vector<int> l, r;
    for (auto v : vec) {
        if (v == farest)
            continue;
        auto sign = GetSign(1, farest, v);
        if (sign > 0)
            l.push_back(v);
        else
            r.push_back(v);
    }

    std::sort(r.begin(), r.end(), [](int a, int b){
        return area12[a] < area12[b];
    });

    std::sort(l.begin(), l.end(), [](int a, int b){
        return area12[a] > area12[b];
    });

    vec.clear();
    for (auto v : r)
        vec.push_back(v);
    vec.push_back(farest);
    for (auto v : l)
        vec.push_back(v);
}

void DumpAns() {
    printf("0 1"); // leading with 0, and start with 1
    for (auto v : right)
        printf(" %d", v);
    printf(" 2");
    for (auto v : left)
        printf(" %d", v);
    printf("\n");
}

/*
任意找两个点将凸多边形分成左右两边,这里简化起见,两个点设置为1和2
向量叉积的符号oa x ob, 根据右手法则,正:b在o的顺时针,a在o的逆时针;负:a在o的顺时针,b在o的逆时针,这里顺时针简化为在o的左边,反之,在o的右边
根据第2条ask规则(即叉积)的方式可以将3-n这些顶点划分到edge1-2这条边的两侧, 需要n-2次ask
由于是凸多边形,那么在同一侧的这些顶点会形成肯定存在一个定位距离edge1-2最远,而且其两侧的顶点到edge1-2这条边分别是递增和递减
这样edge1-2的侧可以排列出来,同理另一侧可以也可以排列出来了
计算距离需要n-2次ask
计算最远点两侧总共需要n-4次ask
所以总的ask复杂度是3n-8
*/
int main() {
    // printf(">\n");
    scanf("%d", &n);
    assert(n >= 3);
    Divide();
    Sort(left);
    Sort(right);
    DumpAns();

    return 0;
}

/*
case
6
-2 1
3 -1
-2 -1
1 -2
0 3
2 2

6
-1
-1
1
1
14
13
-1
10
9
1

4
1
1
2
2
-1


*/
