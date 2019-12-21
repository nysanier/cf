#include <stdio.h>
#include <algorithm>
#include <deque>

const int N = 5000;
int n;
struct St {
    int i;
    int m;
    int p;
    bool operator<(const St& rhs) const {
        return m < rhs.m;
    }
};
St st[N];

int f[N][N];

int dp(int i, int n) {
    if (f[i][n] != -1) {
        return f[i][n];
    }

    if (i == 0 && n == 1) {
        f[i][n] = st[i].p;
        printf("f[%d][%d]=%d\n", i, n, f[i][n]);
        return f[i][n];
    }

    if (n == 0) {
        f[i][n] = 0;
        printf("f[%d][%d]=%d\n", i, n, f[i][n]);
        return f[i][n];
    }

    f[i][n] = std::min(dp(i-1, n-1) + st[i].p, dp(i-1, n));
    printf("f[%d][%d]=%d\n", i, n, f[i][n]);
    return f[i][n];
}

int main() {
    scanf("%d", &n);
    std::deque<St> deq;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &st[i].m, &st[i].p);
        st[i].i = i + 1;
        deq.push_back(st[i]);
    }

    std::sort(deq.begin(), deq.end());
    int C = 0;  // current
    int P = 0;  // back
    while (!deq.empty()) {
        while (!deq.empty()) {
            if (deq.begin()->m <= C) {
                C += 1;
                printf("pop front %d\n", deq.begin()->i);
                deq.pop_front();
                continue;
            } else {
                C += 1;
                P += 1;
                printf("pop back %d\n", deq.rbegin()->i);
                deq.pop_back();
                break;
            }
        }
    }

    printf("P=%d, C=%d\n", P, C);

    auto f2 = (int*)f;
    std::fill(f2, f2 + N * N, -1);
    int ret = dp(n, P);
    printf("ret=%d\n", ret);

    return 0;
}

/*
2
2 10
2 8

*/
