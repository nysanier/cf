#include <bits/stdc++.h>
#include <bits/extc++.h>

// abbr
#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)
#define PB push_back
#define FI first
#define SE second

// type
using ll = long long;
using Vi = std::vector<int>;
using Pi = std::pair<int, int>;
using Si = std::set<int>;
using Mi = std::map<int, int>;
using Ui = std::unordered_map<int, int>;

// -------------------------------------------------
const int N = 2e5 + 9;
const int INF = 1e9 + 21;
int n,m;
Vi a[N];  // 邻接表
bool vis[N];  // 访问标记
int B=0;  // 当前能访问到的最大的点(编号)
void Dfs(int x){
    vis[x]=true;
    B=std::max(B,x);
    for(auto y:a[x])
        if(!vis[y]) Dfs(y);
}
void Solve() {
    scanf("%d%d", &n,&m);
    int x,y;
    for1(i, m) {
        scanf("%d%d", &x,&y);
        a[x].PB(y);
        a[y].PB(x);
    }
    std::fill(vis,vis+n,false);
    int ans=0;
    for1(x,n){
        if(!vis[x]){
            if(x<B) ++ans;
            Dfs(x);
        }
    }
    // output
    // for0(i, n) {
    //     printf("%d ", a[i]);
    // }
    printf("%d\n",ans);
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
