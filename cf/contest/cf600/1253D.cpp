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

// union and find
struct UnionFind {
    static const int N = 2e5 + 9;
    int* p = nullptr;  // for local var

    // all point to self
    UnionFind() {
        p = new int[N];  // root
        for (int i = 0; i < N; ++i) {
            p[i] = i;  // first point to self
        }
    }

    // find the root of x
    int Find(int x) {
        int r = x;
        while (p[r] != r) {
            r = p[r];
        }

        // zip all the element begin x and root
        int i = x;
        while (i != r) {
            int tmp = p[i];
            p[i] = r;  // point to root
            i = tmp;
        }
        return r;
    }

    void Merge(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (rx == ry) return;
        if (rx > ry) std::swap(rx, ry);
        p[rx] = ry;  // point to the max one
    }
};

// -------------------------------------------------
const Int N = 2e5 + 9;
const Int INF = 1e9 + 21;
Int n,m;
UnionFind uf;
void Solve() {
    std::cin >> n >> m;
    Int x,y;
    for1(i, m) {
        std::cin >> x >> y;
        uf.Merge(x,y);
    }
    Int ans=0;
    forxy(i,2,n){  // ?
        Int u=uf.Find(i-1);
        Int v=uf.Find(i);
        if(u>v) {
            ++ans;
            uf.Merge(i-1,i);
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

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#if 0
    Int t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
