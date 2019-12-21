#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

int main() {
    std::vector<int> vec;
    int n;
    scanf("%d", &n);
    vec.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vec[i]);
        // scanf("%d", &x);
        // m.insert(std::make_pair(m, 0));
    }

    std::sort(vec.begin(), vec.end());
    std::multimap<int, int> mmap;
    int i = 1;
    for (auto& v : vec) {
        mmap.insert(std::make_pair(v, i));
        i += 1;
    }
    // std::multimap<int, int> mmap(vec.begin(), vec.end());

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int m;
        scanf("%d", &m);
        // auto it = std::binary_search(vec.begin(), vec.end(), m);
        auto it = mmap.upper_bound(m);
        if (it == mmap.end()) {
            printf("%d\n", n);
        } else {
            printf("%d\n", it->second - 1);
        }
    }

    return 0;
}
