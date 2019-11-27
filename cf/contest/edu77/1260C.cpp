#include <bits/stdc++.h>

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

int T;

void Case() {
    int r, b, k;
    scanf("%d %d %d", &r, &b, &k);
    if (r == b) {
        puts("OBEY");
        return;
    }

    if (r > b) {
        std::swap(r, b);
    }

    auto d = b - r;
    if (d / r >= k) {
        puts("REBEL");
        return;
    }

    puts("OBEY");
}

int main() {
    // printf(">\n");
    scanf("%d", &T);
    while (T--) {
        Case();
    }

    // std::cout << N << std::endl;
    return 0;
}
