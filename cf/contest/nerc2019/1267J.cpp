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
const int N = 2e6 + 9;
const int INF = 1e9 + 21;
int n;
int a[N];
void Solve() {
    scanf("%d", &n);
    Mi mi;
    for0(i, n) {
        scanf("%d", a+i);
        mi[a[i]]+=1;
    }
    std::vector<Pi> v1;
    for(auto& kv:mi){
        v1.PB({kv.SE,kv.FI});
    }
    std::sort(v1.begin(),v1.end());
    int m1=v1[0].FI;
    Si s1{m1+1,m1};
    for(int i=2;i<m1;++i){
        int x=m1/i;
        assert(x*i>=m1);
        if(x*i==m1)
            s1.insert(-x),s1.insert(-x-1);
        else
            s1.insert(-x-1);
    }
    for(auto& v:s1){
        bool flag=true;
        for(auto& kv:mi){
            // if(kv.SE/)
        }
    }
    // output
    // for0(i, n) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");
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
