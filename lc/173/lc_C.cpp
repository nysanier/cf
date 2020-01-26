#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 100 + 9;
const int INF = 1e8;
int mat[N][N];
class Solution {
public:
    void init(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] = INF;
        
        for (auto& v : edges) {
            int a = v[0];
            int b = v[1];
            int w = v[2];
            mat[a][b] = mat[b][a] = w;
        }

        for (int k=0; k<n; k++)
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    if (i != j && mat[i][k]+mat[k][j] < mat[i][j])
                        mat[i][j] = mat[i][k] + mat[k][j];


        // for (int i = 0; i < n; ++i) {
        //     std::vector<int> vec(mat[i], mat[i]+n);
        //     DUMP(i, vec);
        // }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        init(n, edges);
        vector<pair<int, int>> res;  // cnt -> id
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] <= distanceThreshold)
                    cnt += 1;
            }
            res.push_back({cnt, -i});
        }
        std::sort(res.begin(), res.end());
        return -res[0].second;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    int n;
    vector<vector<int>> edges;
    int distanceThreshold;
    lc::ParseArg(in[0], n);
    lc::ParseArg(in[1], edges);
    lc::ParseArg(in[2], distanceThreshold);
    DUMP(n, edges, distanceThreshold);

    Solution sol;
    auto r = sol.findTheCity(n, edges, distanceThreshold);
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
