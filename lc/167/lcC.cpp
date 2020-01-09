#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 300 + 9;
int f[N][N][N];
int R[N][N];
int C[N][N];
// int f[N][N];
class Solution {
    int m, n;
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        m = mat.size();
        n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            R[i][0] = mat[i][0];
            for (int j = 1; j < n; ++j)
                R[i][j] = R[i][j-1] + mat[i][j];
        }
        for (int j = 0; j < n; ++j) {
            C[0][j] = mat[0][j];
            for (int i = 1; i < m; ++i)
                C[i][j] = C[i-1][j] + mat[i][j];
        }

        int ans = 0;
        // 可能的最大边长
        auto m1 = std::min(m, n);
        for (int k = 1; k <= m1; ++k) {  // 枚举[1, m1]
            for (int r = 0; r <= m-k; ++r) {
                for (int c = 0; c <= n-k; ++c) {
                    if (k == 1) {
                        f[r][c][k] = mat[r][c];
                    } else {
                        f[r][c][k] = f[r][c][k-1]
                                        + R[r+k-1][c+k-1] - (c>0?R[r+k-1][c-1]:0)
                                        + C[r+k-1][c+k-1] - (r>0?C[r-1][c+k-1]:0)
                                        - mat[r+k-1][c+k-1];
                    }
                    if (f[r][c][k] <= threshold) ans = k;
                }
            }
        }

        return ans;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    vector<vector<int>> mat;
    int threshold;
    lc::ParseArg(in[0], mat);
    lc::ParseArg(in[1], threshold);
    DUMP(mat, threshold);

    Solution sol;
    auto r = sol.maxSideLength(mat, threshold);
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
