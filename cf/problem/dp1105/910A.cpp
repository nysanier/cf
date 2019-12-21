#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <limits>

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        printf("[%d] %d\n", i, vec[i]);
    }
}

int main() {
    std::string str;
    int n, d;
    scanf("%d %d", &n, &d);
    str.resize(n);
    scanf("%s", &str[0]);
    std::vector<int> vec;
    vec.push_back(0);
    for (int i = 1; i < (int)str.size(); ++i) {
        if (str[i] == '1') {
            vec.push_back(i);
        }
    }

    for (int i = 1; i < (int)vec.size(); ++i) {
        if (vec[i] - vec[i-1] > d) {
            printf("-1\n");
            return 0;
        }
    }

    std::vector<int> dp;
    dp.resize(vec.size());
    std::fill(dp.begin(), dp.end(), std::numeric_limits<int>::max());
    dp[0] = 0;
    for (int i = 0; i < (int)dp.size(); ++i) {
        for (int j = i + 1; j < (int)dp.size(); ++j) {
            if (vec[j] - vec[i] > d) {
                break;
            }

            dp[j] = std::min(dp[j], dp[i] + 1);
        }
    }

    // Dump(dp);

    printf("%d\n", *dp.rbegin());

    return 0;
}
