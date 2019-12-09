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

// debug
template<typename... Args>
std::string format(const std::string& fmt, Args... args) {
    auto sz = ::snprintf(nullptr, 0, fmt.c_str(), args...);
    std::string buf(sz, '?');
    ::snprintf(&buf[0], sz + 1, fmt.c_str(), args...);
    return buf;
}
#ifndef ONLINE_JUDGE
# define dbg(fmt, args...) (std::clog << "***DEBUG*** " << format(fmt, ##args) << std::endl)
# define VAR(e) (#e "=") << (e) << (",")
# define VAR2(e1,e2) VAR(e1) << VAR(e2)
# define VAR4(e1,e2,e3,e4) VAR2(e1,e2) << VAR2(e3,e4)
# define dump(e) (std::clog << "***DEBUG*** " << VAR(e) << std::endl)
# define dump2(e1,e2) (std::clog << "***DEBUG*** " << VAR2(e1,e2) << std::endl)
# define dump3(e1,e2,e3) (std::clog << "***DEBUG*** " << VAR2(e1,e2) << VAR(e3) << std::endl)
# define dump4(e1,e2,e3,e4) (std::clog << "***DEBUG*** " << VAR4(e1,e2,e3,e4) << std::endl)
# define dump5(e1,e2,e3,e4,e5) (std::clog << "***DEBUG*** " << VAR4(e1,e2,e3,e4) << VAR(e5) << std::endl)
# define dump6(e1,e2,e3,e4,e5,e6) (std::clog << "***DEBUG*** " << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << std::endl)
# define dump7(e1,e2,e3,e4,e5,e6,e7) (std::clog << "***DEBUG*** " << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << VAR(e7) << std::endl)
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

// type
using ll = long long;
using Vi = std::vector<int>;
using Pi = std::pair<int, int>;
using Si = std::set<int>;
using Mi = std::map<int, int>;

// -------------------------------------------------
// const int N = 1e6 + 9;
// const int INF = 1e9 + 21;
int n;
int a,b;
void Solve() {
    scanf("%d%d%d", &n,&a,&b);
    // for0(i, n) {
    //     scanf("%d", a+i);
    // }
    Si si;
    for1(i,n-1){
        int t=n-i;
        int k1=a/i;
        int k2=b/t;
        int m=std::min(k1,k2);
        if(m==0) continue;
        dump5(i,t,k1,k2,m);
        si.insert(m);
    }
    // output
    // for0(i, n) {
    //     printf("%d ", a[i]);
    // }
    printf("%d\n",*--si.end());
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
