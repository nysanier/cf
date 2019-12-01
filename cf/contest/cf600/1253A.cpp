#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
const int N = 1e5 + 9;

int n;
int a[N];
int b[N];

void Solve() {
    scanf("%d",&n);
    std::vector<int> vec(n);
    for0(i,n) scanf("%d",a+i);
    for0(i,n) scanf("%d",b+i), vec[i]=b[i]-a[i];
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
    if (vec.size() == 1u && vec[0] >= 0) {
        puts("YES");
        return;
    }

    if (vec.size() == 2u) {
        if (vec[0] == 0 && vec[1] > 0) {
            puts("YES");
            return;
        }

        if (vec[0] > 0 && vec[1] == 0) {
            puts("YES");
            return;
        }
    }

    if (vec.size() == 3u) {
        if (vec[0] == 0 && vec[1] > 0 && vec[2] == 0) {
            puts("YES");
            return;
        }
    }

    puts("NO");
}

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

#if 1
    int t;
    scanf("%d", &t);
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
