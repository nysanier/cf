#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int k = 0; k < m; ++k) {
            vector<int> vec;
            for (int x = k; x < m; ++x) {
                int y = x - k;
                if (y < 0 || y >= n) break;
                DUMP('m', x, y);
                vec.push_back(mat[x][y]);
            }
            // DUMP(k, vec);
            std::sort(vec.begin(), vec.end());
            int idx = 0;
            for (int x = k; x < m; ++x) {
                int y = x - k;
                if (y < 0 || y >= n) break;
                mat[x][y] = vec[idx++];
            }
        }

        for (int k = 1; k < n; ++k) {
            vector<int> vec;
            for (int y = k; y < n; ++y) {
                int x = y - k;
                DUMP('n', x, y);
                if (x < 0 || x >= m) break;
                vec.push_back(mat[x][y]);
            }
            std::sort(vec.begin(), vec.end());
            int idx = 0;
            for (int y = k; y < n; ++y) {
                int x = y - k;
                if (x < 0 || x >= m) break;
                mat[x][y] = vec[idx++];
            }
        }
        return mat;
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
    lc::ParseArg(in[0], mat);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    DUMP(mat);

    Solution sol;
    auto r = sol.diagonalSort(mat);
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
