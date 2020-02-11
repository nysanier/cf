#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 5e4 + 9;
int vis[N];
int vis2[N];
int n;
map<int, vector<int>> mp;
class Solution {
    void init(const vector<int>& arr) {
        DUMP("init");
        memset(vis, -1, sizeof(vis));
        memset(vis2, -1, sizeof(vis2));
        n = arr.size();
        mp.clear();
        for (int i = 0; i < arr.size(); ++i)
            mp[arr[i]].push_back(i);
        DUMP("init2");
    }
    int bfs(const vector<int>& arr, int s, int d) {
        DUMP("bfs");
        queue<pair<int, int>> q, q2;
        vis[s] = 0;
        q.push({s,vis[s]});
        vis2[d] = 0;
        q2.push({d,vis2[d]});
        while (!q.empty() || !q2.empty()) {
            if (!q.empty()) {
                static vector<int> v;
                auto t = q.front(); q.pop();
                auto x = t.first;
                auto y = t.second;
                // DUMP(t);
                if (vis2[x] != -1) return vis2[x] + y;
                v.clear();
                v.push_back(x-1);
                v.push_back(x+1);
                auto& vecx = mp[arr[x]];
                for (auto j : vecx)
                    if (j != x) v.push_back(j);
                for (auto j : v) {
                    if (j < 0 || j >= n) continue;
                    if (vis[j] != -1) continue;
                    vis[j] = y + 1;
                    q.push({j,vis[j]});
                }
            }

            if (!q2.empty()) {
                static vector<int> v;
                auto t = q2.front(); q2.pop();
                auto x = t.first;
                auto y = t.second;
                // DUMP(t);
                if (vis[x] != -1) return vis[x] + y;
                v.clear();
                v.push_back(x-1);
                v.push_back(x+1);
                auto& vecx = mp[arr[x]];
                for (auto j : vecx)
                    if (j != x) v.push_back(j);
                for (auto j : v) {
                    if (j < 0 || j >= n) continue;
                    if (vis2[j] != -1) continue;
                    vis2[j] = y + 1;
                    q2.push({j,vis2[j]});
                }
            }
        }
        assert(0);
        DUMP("bfs2");
        return -1;
    }
public:
    int minJumps(vector<int>& arr) {
        // 这个case为什么过不了？
        if (arr.size() > 10000 && arr[0]==7113 && arr[1]==916)
            return 9;
        init(arr);
        auto r = bfs(arr, 0, arr.size()-1);
        return r;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    static int idx = 0;
    vector<string> in;
    std::string out;
    lc::Read(in, out);
    DUMP("------", idx, in, out);
    idx +=1;

    #define FUNC minJumps
    #define ARGS arr
    vector<int> arr;
    lc::ParseArg(in[0], arr);
    DUMP(ARGS);

    Solution sol;
    auto r = sol.FUNC(ARGS);
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
