#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> vec;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; ++i) {
            int a = std::accumulate(mat[i].begin(), mat[i].end(), 0);
            vec.push_back({a, i});
        }
        std::sort(vec.begin(), vec.end());
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(vec[i].second);
        }
        return res;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    string s;
    lc::ParseArg(in[0], s);
    DUMP(s);

    Solution sol;
    auto r = sol.removePalindromeSub(s);
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
