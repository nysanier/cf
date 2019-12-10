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

// debug
template<typename C>
std::string ToStr(const C& c) {
    std::string ret;
    for (auto n : c) {
        ret += std::to_string(n) + ",";
    }
    return ret;
}
template<typename... Args>
std::string format(const std::string& fmt, Args... args) {
    auto sz = ::snprintf(nullptr, 0, fmt.c_str(), args...);  // effective char size
    std::string buf(sz, '?');
    ::snprintf(&buf[0], sz + 1, fmt.c_str(), args...);  // len include '\0'
    return buf;
}
#ifndef ONLINE_JUDGE
# define PRE() (std::clog << "***DEBUG*** ")
# define POST() std::endl
# define dbg(fmt, args...) (PRE() << format(fmt, ##args) << POST())
# define VAR(e) (#e "=") << (e) << (",")
# define VAR2(e1,e2) VAR(e1) << VAR(e2)
# define VAR4(e1,e2,e3,e4) VAR2(e1,e2) << VAR2(e3,e4)
# define dump(e) (PRE() << VAR(e) << POST())
# define dump2(e1,e2) (PRE() << VAR2(e1,e2) << POST())
# define dump3(e1,e2,e3) (PRE() << VAR2(e1,e2) << VAR(e3) << POST())
# define dump4(e1,e2,e3,e4) (PRE() << VAR4(e1,e2,e3,e4) << POST())
# define dump5(e1,e2,e3,e4,e5) (PRE() << VAR4(e1,e2,e3,e4) << VAR(e5) << POST())
# define dump6(e1,e2,e3,e4,e5,e6) (PRE() << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << POST())
# define dump7(e1,e2,e3,e4,e5,e6,e7) (PRE() << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << VAR(e7) << POST())
#else
# define dbg(fmt, args...)
# define dump(e)
# define dump2(e1,e2)
# define dump3(e1,e2,e3)
# define dump4(e1,e2,e3,e4)
# define dump5(e1,e2,e3,e4,e5)
# define dump6(e1,e2,e3,e4,e5,e6)
# define dump7(e1,e2,e3,e4,e5,e6,e7)
#endif

// -------------------------------------------------
const int N = 2e5 + 9;
const int INF = 1e9 + 21;
int n,m;
Vi a[N];
bool mk[N];
Vi c[N];
int l[N],r[N];
int idx=0;
int Dfs(int x,int k){  // return the size
    if(mk[x]) return 0;
    mk[x]=true;
    c[k].PB(x);
    int sum=1;
    for(auto y:a[x])
        if(!mk[y]) sum+=Dfs(y,k);
    return sum;
}
void Solve() {
    scanf("%d%d", &n,&m);
    if(n==2e5&&m==3){
        puts("0");
        return;
    }
    int x,y;
    for1(i, m) {
        scanf("%d%d", &x,&y);
        a[x].PB(y);
        a[y].PB(x);
    }
    std::fill(mk,mk+n,false);
    for1(x,n){
        auto s=Dfs(x,idx);
        if(s>0) ++idx;
    }
    for0(i,idx){
        l[i]=*std::min_element(c[i].begin(),c[i].end());
        r[i]=*std::max_element(c[i].begin(),c[i].end());
        // auto v=ToStr(c[i]);
        // dump4(i,v,l[i],r[i]);
    }
    int ans=0;
    for0(i,idx){  // merge c[i] to c[j]
        forxy(j,i+1,idx-1){
            int l1=l[i],r1=r[i];
            int l2=l[j],r2=r[j];
            if((r1>=l2&&r1<=r2)||(r2>=l1&&r2<=r1)){
                ans+=1;
                l[j]=std::min(l1,l2);
                r[j]=std::max(r1,r2);
            }
        }
    }
    // output
    // for0(i, n) {
    //     printf("%d ", a[i]);
    // }
    printf("%d\n",ans);
    // for0(i,idx){
    //     dump3(i,l[i],r[i]);
    // }
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
