#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)
#define PB push_back
#define FI first
#define SE second

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
const int INF = 1e9 + 21;
int n,m;
int a[N];
void Solve() {
    scanf("%d%d", &n,&m);
    int sum=0;
    int m1=0;
    for0(i, n) {
        scanf("%d", a+i);
        sum+=a[i];
        m1=std::max(m1,a[i]);
    }
    std::sort(a,a+n);
    sum+=m;
    int k1=(sum+n-1)/n;
    k1=std::max(k1,m1);
    int k2=a[n-1]+m;
    // output
    // for0(i, n) {
    //     printf("%d ", a[i]);
    // }
    printf("%d %d\n",k1,k2);
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
