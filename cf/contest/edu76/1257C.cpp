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
using Pii = std::pair<int, int>;
using Si = std::set<int>;
using Mii = std::map<int, int>;

// -------------------------------------------------
const int N = 2e5 + 9;
int n;
int a[N];
int f[N];
const int inf=1e9;
void Solve() {
    scanf("%d",&n);
    for0(i,n){
        scanf("%d",a+i);
    }
    if(n==1)
        {puts("-1");return;}
    Mii mapx;
    for0(i,n){
        auto it=mapx.find(a[i]);
        if(it==mapx.end())
            f[i]=inf,mapx[a[i]]=i;
        else
            f[i]=i-it->se+1,it->se=i;
    }
    int m=inf;
    for0(i,n)
        if(f[i]<m) m=f[i];
    if(m==inf) m=-1;
    printf("%d\n",m);
}
// -------------------------------------------------

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
