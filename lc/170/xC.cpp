#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    static const int N = 100 + 9;
    int vis[N];
    std::set<int> res;  // all level friends;
    void init(vector<vector<int>>& friends) {
        memset(vis, 0, sizeof(vis));
    }
    void bfs(vector<vector<int>>& friends, int s, int level) {
        std::queue<std::pair<int,int>> q;
        q.push({s,0});
        vis[s] = 1;
        // DUMP("init", s, 0);
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            auto i = t.first;
            auto l = t.second;
            if (l == level) {
                DUMP("res add", i);
                res.insert(i);
            }
            for (auto j : friends[i]) {
                if (!vis[j]) {
                    auto nl = l + 1;
                    DUMP("find", i, j, nl);
                    vis[j] = 1;
                    q.push({j, nl});
                }
            }
        }
    }

public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        init(friends);
        bfs(friends, id, level);
        DUMP(res);
        std::map<std::string, int> mp;
        for (auto v : res) {
            for (auto& w : watchedVideos[v]) {
                mp[w] += 1;
            }
        }
        std::vector<std::pair<int, std::string>> vec;
        for (auto& kv : mp)
            vec.push_back({kv.second, kv.first});
        std::sort(vec.begin(), vec.end());
        vector<string> r;
        for (auto& pr : vec)
            r.push_back(pr.second);
        return r;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    // 输入有问题!!!
    // vector<vector<string>> watchedVideos{{"A","B"},{"C"},{"B","C"},{"D"}};
    // vector<vector<int>> friends{{1,2},{0,3},{0,3},{1,2}};
    // int id = 0;
    // int level = 1;
    vector<vector<string>> watchedVideos;
    vector<vector<int>> friends;
    int id;
    int level;
    lc::ParseArg(in[0], watchedVideos);
    lc::ParseArg(in[1], friends);
    lc::ParseArg(in[2], id);
    lc::ParseArg(in[3], level);
    DUMP(watchedVideos, friends, id, level);

    Solution sol;
    auto r = sol.watchedVideosByFriends(watchedVideos, friends, id, level);
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
