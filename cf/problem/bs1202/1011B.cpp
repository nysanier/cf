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

// -------------------------------------------------
const int N = 1e2 + 9;
const int INF = 1e9 + 21;
int n,m;
int a[N];
void Solve() {
    scanf("%d%d", &n,&m);
    Mi mi;
    for0(i, m) {
        scanf("%d", a+i);
        mi[a[i]]+=1;
    }
    Si res{0};
    for(int i=1;;++i){
        int sum=0;
        for(auto& kv:mi){
            sum+=kv.SE/i;
        }
        if(sum>=n) res.insert(i);
        else break;
    }
    // output
    // for0(i, n) {
    //     printf("%d ", a[i]);
    // }
    printf("%d\n",*--res.end());
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
