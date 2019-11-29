#include "bits/stdc++.h"

int t;
void Case() {
    std::set<int> setx;
    int n;
    scanf("%d", &n);
    setx.insert(0);
    for (int k = 1; k * k <= n; ++k) {
        setx.insert(k);
        setx.insert(n / k);
    }

    printf("%d\n", (int)setx.size());
    for (auto v : setx) {
        printf("%d ", v);
    }
    printf("\n");
}

int main() {
    // printf(">\n");
    scanf("%d", &t);
    while (t--) {
        Case();
    }

    return 0;
}
