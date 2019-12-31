#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// bfs的时候先标记状态再送到队列，虽然两次处理，但是可以保证队列里面的元素唯一
// 类似dfs，其实可以人队列，然后处理，或者用set等也是可以的
// # define DUMP(args...)
class Solution {
    static const int N = 1000 + 9;
    set<int> res;
    bool vis[N];
    bool box[N];
    bool key[N];
    void init() {
        std::fill(vis, vis+N, false);
        std::fill(box, box+N, false);
        std::fill(key, key+N, false);
    }
    void bfs(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        for (auto b : initialBoxes)
            if (!vis[b])
                q.push(b), vis[b]=true;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            // DUMP("test", t);
            box[t] = true;
            // DUMP("box", t);
            if (status[t]) {
                key[t] = true;
                // DUMP("key", t);
            }
            for (auto k : keys[t]) {
                key[k] = true;
                // DUMP("key", k);
            }
            for (auto b : containedBoxes[t])
                if (!vis[b])
                    q.push(b), vis[b]=true;
        }
    }
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        init();
        bfs(status, candies, keys, containedBoxes, initialBoxes);
        int sum = 0;
        for (int i = 0; i < status.size(); ++i) {
            if (box[i] && key[i]) {
                // DUMP("find", i);
                sum += candies[i];
            }
        }
        return sum;
    }
};
}

int n;
vector<string> words;
string result;
void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    lc::Readin(in);

    vector<int> status; vector<int> candies; vector<vector<int>> keys; vector<vector<int>> containedBoxes; vector<int> initialBoxes;
    lc::ParseArg(in[0], status);
    lc::ParseArg(in[1], candies);
    lc::ParseArg(in[2], keys);
    lc::ParseArg(in[3], containedBoxes);
    lc::ParseArg(in[4], initialBoxes);
    DUMP(status, candies, keys, containedBoxes, initialBoxes);

    Solution sol;
    auto r = sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes);
    DUMP(r);
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
