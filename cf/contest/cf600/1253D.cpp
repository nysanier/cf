#include <bits/stdc++.h>
#include <bits/extc++.h>

// abbr
using Int = int32_t;
// using Int = int64_t;
#define for0(i, n) for (Int i = 0; i < Int(n); ++i)
#define for1(i, n) for (Int i = 1; i <= Int(n); ++i)
#define for0r(i, n) for (auto i = Int(n-1); i >= 0; --i)
#define for1r(i, n) for (auto i = Int(n); i >= 1; --i)
#define forxy(i, x, y) for (auto i = Int(x); i <= Int(y); ++i)
#define foryx(i, x, y) for (auto i = Int(y); i >= Int(x); --i)
#define PB push_back
#define FI first
#define SE second

// type
using Vec = std::vector<Int>;
using Pair = std::pair<Int, Int>;
using Set = std::set<Int>;
using Map = std::map<Int, Int>;
using Hash = std::unordered_map<Int, Int>;

// -------------------------------------------------
const Int N = 2e5 + 9;
const Int INF = 1e9 + 21;
Int n,m;
Vec a[N];  // 邻接表
bool vis[N];  // 访问标记
Int B=0;  // 当前能访问到的最大的点(编号)
void Dfs(Int x){
    vis[x]=true;
    B=std::max(B,x);
    for(auto y:a[x])
        if(!vis[y]) Dfs(y);
}
void Solve() {
    scanf("%d%d", &n,&m);
    Int x,y;
    for1(i, m) {
        scanf("%d%d", &x,&y);
        a[x].PB(y);
        a[y].PB(x);
    }
    std::fill(vis,vis+n,false);
    Int ans=0;
    for1(x,n){
        if(!vis[x]){
            if(x<B) ++ans;
            Dfs(x);
        }
    }
    // output
    std::cout << ans << std::endl;
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(nullptr);

#if 0
    Int t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
