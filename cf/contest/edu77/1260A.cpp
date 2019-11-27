#include <bits/stdc++.h>

using ll = long long;

int n;

void Case() {
    int c, sum;
    scanf("%d %d", &c, &sum);

    int x = sum / c;
    if (c * x < sum) {
        x += 1;
    }
    // printf("x = %d\n", x);

    std::map<int, int> mapx;
    for (int a = 0; a <= c; ++a) {
        int s = a * x + (c - a) * (x - 1);
        if (s >= sum) {
            mapx[s] = a;
        }
    }

    auto a = mapx.begin()->second;
    // printf("a = %d\n", a);
    ll res = a * ll(x) * x + (c - a) * ll(x - 1) * (x - 1);

    printf("%lld\n", res);
}

int main() {
    // printf(">\n");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        Case();
    }

    return 0;
}
