#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 40 + 9;
const int INF = 1e9;
int a[N*N][N][N];
class Solution {
    int m, n;
    vector<vector<int>> g;
    void init() {
        // memset(a, -1, sizeof(a));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                std::fill(a[i][j], a[i][j]+N*N, INF);
    }
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
public:
    // 递推式写不出来啊！！！！
    int shortestPath(vector<vector<int>>& grid, int k) {
        init();
        m = grid.size();
        n = grid[0].size();
        // a[0][0][0] = 0;
        for (int p = 0; p <= k; ++p) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    // init
                    if (i == 0 && j == 0) { a[p][i][j] = 0; continue; }
                    if (p > 0) a[p][i][j] = std::min(a[p][i][j], a[p-1][i][j]);
                    else a[p][i][j] = INF;
                    // iterator
                    for (int d = 0; d < 4; ++d) {
                        auto i2 = i + dir[d][0];
                        auto j2 = j + dir[d][1];
                        if (i2<0 || i2>=m || j2<0 || j2>=n) continue;
                        // if (p == 0) {  // 初次计算
                        //     if (grid[i][j] == 0)  // 只计算可达位置
                        //         a[p][i][j] = std::min(a[p][i][j], a[p][i2][j2]+1);
                        //     continue;
                        // }
                        if (grid[i][j] == 0) {
                            a[p][i][j] = std::min(a[p][i][j], a[p][i2][j2]+1);
                            if (grid[i2][j2] == 0)
                                a[p][i2][j2] = std::min(a[p][i2][j2], a[p][i][j]+1);
                        } else if (p > 0) {
                            a[p][i][j] = std::min(a[p][i][j], a[p-1][i2][j2]+1);
                            a[p][i2][j2] = std::min(a[p][i2][j2], a[p][i][j]+1);
                        }
                    }
                }
            }

            for (int i = 0; i < m; ++i) {
                std::vector<int> vec(a[p][i], a[p][i]+n);
                DUMP(p, vec);
            }
        }

        auto r = a[m-1][n-1][k];
        if (r == INF) return -1;
        else return r;
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
