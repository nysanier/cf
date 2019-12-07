#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)
#define pb push_back
#define fi first
#define se second

#ifndef ONLINE_JUDGE
# define dbg(fmt, args...) printf("***DEBUG*** " fmt "\n", ##args)
#else
# define dbg(fmt, args...)
#endif
#define dump(e) dbg("dump: " #e "=%d", e)

using ll = long long;
using Vi = std::vector<int>;
using Pi = std::pair<int, int>;
using Si = std::set<int>;
using Mi = std::map<int, int>;

// -------------------------------------------------
const int N = 1e2 + 9;
int n,m;
int a[N][N];
int res[N];
void Solve() {
    scanf("%d %d", &n, &m);
    for0(i, m) {
        for0(j, n)
            scanf("%d", a[i]+j);
    }
    int ans = m;
    for0(i, m) res[i] = i;
    for0(i, n-1) {  // for all other n-1 candidates
        dump(i);
        Pi pi[N];
        for0(j, m) pi[j] = {a[j][n-1]-a[j][i], j};
        std::sort(pi, pi+m);
        int sum = 0;
        int j = 0;
        for (; j < m; ++j) {  // pick more poll stations
            sum -= pi[j].fi;
            if (sum < 0) {
                dump(sum);
                break;
            }
        }
        if (m-j < ans) {  // the other poll stations must be canceled
            dbg("new ans i = %d, j = %d", i, j);
            ans = m-j;
            forxy(p, j, m-1) res[p-j] = pi[p].se;
        }
    }
    printf("%d\n", ans);
    for0(i, ans) {
        printf("%d ", res[i]+1);
    }
    printf("\n");
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

#if 0
    int t;
    scanf("%d", &t);
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
