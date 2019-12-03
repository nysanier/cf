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

// less than 1e5 is possible
namespace solve1 {

    int n;
    int a[N];
    std::vector<int> ans[N * 2];  // max 99999 * 2

    int GetN(int a) {
        int ar = 0;
        int tmp = a;
        while (tmp > 0) {
            ar = ar * 10 + tmp % 10;
            tmp /= 10;
        }

        return a + ar;
    }

    int Main() {
        for (int i = 1; i <= 1e5; ++i) {
            int v = GetN(i);
            ans[v].push_back(i);
        }

        // scanf("%d", &n);
        for (int n = 1; n <= 1000; ++n) {
            if (ans[n].empty()) {
                // printf("%d: 0\n", n);1
                continue;
            }

            printf("%d:", n);
            for (auto v : ans[n]) printf(" %d", v);
            printf("\n");
        }
        return 0;
    }
}

// 经典的子问题解决方案:
//     根据最后一位数字和最前面的数字推算出前后两位,然后得到中间一段数字. 中间的这一段数字就是一个子问题, 且不受前后两个数字的影响!!
// 如果last1(n) = 9, 那么first(n) = 9 or first2(n) = 10
// 如果last1(n) = X(!= 9)
// 那么first2(n) = 
//      0, X
//      0, X+1
//      1, X
//      1, X+1

namespace solve {
    char s[N];
    char ans[N];
    bool Parse() {
        auto len = strlen(s);
        int i = 0;
        int j = len - 1;
        while (i < j) {
            if (s[j] == '9') {
                if (s[i] == '9') {
                    ans[j] = '0';
                    ans[i] = '9';
                    s[i] = s[j] = 'x';
                    i += 1;
                    j -= 1;
                    continue;
                } else if (i+1 < j && s[i] == '1' && s[i+1] == '0') {
                    ans[j] = '0';
                    ans[i] = '9';
                    s[j] = 'x';
                    s[i+1] = '1';
                    i += 1;
                    j -= 1;
                    continue;
                } else {
                    return false;
                }
            }

            if (i+1 < j && s[i] == '1')
                if (s[i+1] == s[j]+1) {
                    ans[i] = '9';
                    ans[j] = ((10 + s[j] - '0') - '9') + '0';
                    s[j] = 'x';
                    s[i+1] = '1';
                    i += 1;
                    j -= 1;
                } else if (s[i+1] == s[j]) {
                    ans[i] = '9';
                    ans[j] = 
                }

            } 
        }

        if (i == j) {
            auto v = s[0]-'0';
            if (v % 2 != 0)
                return false;
            }
            ans[i] = v / 2;
        }

        return true;
    }
    int Main() {
        scanf("%s", &s);
    
    }
}

int main() {
    // printf(">\n");
    return solve1::Main();

    return 0;
}
