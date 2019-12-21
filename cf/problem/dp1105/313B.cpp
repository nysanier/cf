#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <limits>
#include <map>
#include <string.h>

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

std::string s;
int Sum(int l, int r) {
    int sum = 0;
    for (int x = l; x < r; ++x) {
        if (s[x] == s[x+1]) {
            // printf("s[%d] == s[%d]\n", x, x+1);
            sum += 1;
        }
    }

    return sum;
}

int dp[100000];

int main() {
    s.resize(100000);
    scanf("%s", &s[0]);
    auto n = strlen(s.c_str());
    // printf("n = %d\n", (int)n);
    s.resize(n);

    dp[0] = 0;
    for (int r = 1; r < n; ++r) {
        dp[r] = dp[r-1];
        if (s[r-1] == s[r]) dp[r] += 1;
    }

    int m;
    scanf("%d", &m);
    std::vector<int> vec;
    std::multimap<std::pair<int, int>, size_t> map_index;
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        int ret = dp[r-1] - dp[l-1];
        printf("%d\n", ret);
    }

    return 0;
}
