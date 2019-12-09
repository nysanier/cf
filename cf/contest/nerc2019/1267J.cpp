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
const int N = 2e6 + 9;
const int INF = 1e9 + 21;
int n;
int a[N];
void Solve() {
    scanf("%d", &n);
    Ui map1;
    for0(i, n) {
        scanf("%d", a+i);map1[a[i]]+=1;
    }
    std::vector<Pi> vec1;
    for(auto& kv:map1)
        vec1.PB({kv.SE,kv.FI});
    std::sort(vec1.begin(),vec1.end());
    int m1=vec1[0].FI;
    Si set1{1};
    forxy(i,2,m1+1){
        bool flag=true;
        for(auto v:vec1){
            int t=(v.FI+i-1)/i;
            if(v.FI<t*(i-1)) {flag=false;break;}
        }
        if(flag) set1.insert(i);
    }
    int s=*--set1.end();  // the max size
    int sum=0;
    for(auto v:vec1)
        sum=(v.FI+s-1)/s;
    printf("%d\n",sum);
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
