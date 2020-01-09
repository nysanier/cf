#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 40 + 9;
int vis[N][N];
const int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
class Solution {
    struct S {
        int r, c;  // 当前的位置
        int k;  // 当前还能经过的障碍物个数
        int d;  // 当前经过的步数
    };
    int m, n;
    void init() {
        memset(vis, 0, sizeof(vis));
    }
public:
    // 递推式写不出来啊！！！！
    // 这类题居然用的是bfs！！！怪不得写不错递推式，而且C已经考察了递推，那么D就不应该是递推
    int shortestPath(vector<vector<int>>& grid, int k) {
        init();
        m = grid.size();
        n = grid[0].size();
        std::queue<S> q;
        q.push({0,0,k,0});
        vis[0][0] = 1;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            if (t.r == m-1 && t.c == n-1) return t.d;
            for (int d = 0; d < 4; ++d) {
                auto nr = t.r + dir[d][0];
                auto nc = t.c + dir[d][1];
                if (nr<0 || nr>=m || nc<0 || nc>=n) continue;
                auto nk = t.k - (grid[nr][nc]?1:0);
                auto nd = t.d + 1;
                if (nk < 0) continue;
                if (!vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc,nk,nd});
                }
            }
        }
        return -1;  // 找不到解决方案
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    vector<vector<int>> grid;
    int k;
    lc::ParseArg(in[0], grid);
    lc::ParseArg(in[1], k);
    DUMP(grid, k);

    Solution sol;
    auto r = sol.shortestPath(grid, k);
    DUMP(out, r);
    // assert(out == to_string(r));
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Init();
    int t = 1;
    std::cin >> t;
    while (t--) Solve();

    return 0;
}
