#include "bits/stdc++.h"

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
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    // std::cout << N << std::endl;
    return 0;
}
