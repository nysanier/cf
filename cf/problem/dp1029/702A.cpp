#include <stdio.h>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec;
    int n;
    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
    }

    // std::sort(vec.begin(), vec.end());
    // auto it = std::unique(vec.begin(), vec.end());
    // auto it2 = it;
    // for (; it2 != vec.end(); ++it2) {
    //     printf("[] %d\n", *it2);
    // }
    // vec.erase(it, vec.end());
    // printf("%d\n", (int)vec.size());

    int ret = 1;
    int cur = vec[0];
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (vec[i] > cur) {
            count += 1;
            ret = std::max(ret, count);
            cur = vec[i];
        } else {
            count = 1;
            cur = vec[i];
        }
    }

    printf("%d\n", ret);

    return 0;
}
