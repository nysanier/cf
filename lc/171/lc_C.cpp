#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 1e5 + 9;
int vis[N];
class Solution {
    int sz;
    vector<vector<int>> conn;
    void init(int n, vector<vector<int>>& connections) {
        memset(vis, 0, sizeof(vis));
        sz = n;
        conn.resize(sz);
        for (auto& kv : connections) {
            conn[kv[0]].push_back(kv[1]);
            conn[kv[1]].push_back(kv[0]);
        }
    }
    void dfs(int x) {
        DUMP("dfs", x);
        // if (vis[x]) {
        //     DUMP("EEEEE");
        //     return;
        // }
        for (auto y : conn[x]) {
            if (!vis[y]) {
                vis[y] = 1;
                dfs(y);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        init(n, connections);
        if (connections.size() < n-1) return -1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                // DUMP(i);
                ans += 1;
                vis[i] = 1;
                dfs(i);
            }
        }
        return ans - 1;
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
    vector<vector<int>> connections;
    lc::ParseArg(in[0], n);
    lc::ParseArg(in[1], connections);
    DUMP(n, connections);

    Solution sol;
    auto r = sol.makeConnected(n, connections);
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
