#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (decltype(n) i = x; i < (n)+(x); ++i)
#define fornr(i, x, n) for (auto i = (n)-1+(x); i >= x; --i)
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (auto i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (auto i = y; i >= x; i -= d)
#define forxy(i, x, y) forxyd(i, x, y, 1)
#define foryx(i, x, y) foryxd(i, x, y, 1)
#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

// type
// using ll = int32_t;
using ll = int64_t;
using Vec = std::vector<ll>;
using Deq = std::deque<ll>;
using Lst = std::list<ll>;
using Pr = std::pair<ll, ll>;
using St = std::set<ll>;
using Mst = std::multiset<ll>;
using Ust = std::unordered_set<ll>;
using Mp = std::map<ll, ll>;
using Mmp = std::multimap<ll, ll>;
using Ump = std::unordered_map<ll, ll>;

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
            DUMP("test", t);
            box[t] = true; DUMP("box", t);
            if (status[t]) { key[t] = true; DUMP("key", t); }
            for (auto k : keys[t])
                { key[k] = true; DUMP("key", k); }
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
                DUMP("find", i);
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
    vector<int> status{1,0,1,0};
    vector<int> candies{7,5,4,100};
    vector<vector<int>> keys{{},{},{1},{}};
    vector<vector<int>> containedBoxes{{1,2},{3},{},{}};
    vector<int> initialBoxes{0};
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
    ll t = 1;
    // std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
