#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    std::vector<int> vec;
    int n, m;
    scanf("%d %d", &n, &m);
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }

    // preprocess
    std::vector<int> vec2;
    vec2.resize(n);
    vec2[n - 1] = 1;
    std::set<int> vecset = {vec[n - 1]};
    for (int i = n - 2; i >= 0; --i) {
        if (vecset.find(vec[i]) == vecset.end()) {
            vec2[i] = vec2[i + 1] + 1;
            vecset.insert(vec[i]);
        } else {
            vec2[i] = vec2[i + 1];
        }
    }

    // queries
    for (int i = 0; i < m; ++i) {
        int l;
        scanf("%d", &l);
        printf("%d\n", vec2[l - 1]);
    }

    return 0;
}
