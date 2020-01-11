#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // int sum = 0;
                ret[i][j] = 0;
                for (int r = i-K; r <= i+K; ++r) {
                    for (int c = j-K; c <= j+K; ++c) {
                        if (r<0 || r>=m || c<0 || c>=n) continue;
                        ret[i][j] += mat[r][c];
                    }
                }            
            }
        }
        return ret;
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
    int K;
    lc::ParseArg(in[0], mat);
    lc::ParseArg(in[1], K);
    DUMP(mat, K);

    Solution sol;
    auto r = sol.matrixBlockSum(mat, K);
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
