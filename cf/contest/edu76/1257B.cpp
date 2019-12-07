#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)

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
int x,y;
void Solve() {
    scanf("%d%d",&x,&y);
    if(y==1) {
        puts("YES");
        return;
    }
    if(x==1) {
        puts("NO");
        return;
    }
    // 2->1|3->2, so 2|3->2|3
    if(x==2||x==3) {
        if(y==2||y==3) puts("YES");
        else puts("NO");
        return;
    }
    // n -> 4 if n > 4
    // 4 -> 6 -> 9 -> 8 -> 12 -> 18 -> 27 -> 26 -> 39 -> 38 -> 57 -> 56 ... -> inf -> inf-1 -> every y
    puts("YES");
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
