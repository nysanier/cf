#include "bits/stdc++.h"

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
const int N = 1e6 + 9;

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

template <typename C>
void Dump(const C& c) {
    for (auto v : c) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", v);
    }
}

int n;
int a[N];

int main() {
    // printf(">\n");
    scanf("%d", &n);
    for0(i, n) {
        scanf("%d", a + i);
    }

    for0r(i, n) {
        printf("%d\n", a[i]);
    }

    return 0;
}
