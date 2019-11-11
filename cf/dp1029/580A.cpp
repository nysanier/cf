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

    int ret = 0;
    int v = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        if (vec[i] >= v) {
            l += 1;
            v = vec[i];
            ret = std::max(ret, l);
        } else {
            l = 1;
            v = vec[i];
        }
    }

    printf("%d\n", ret);

    return 0;
}
