#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    using Pair = pair<uint64_t, uint64_t>;
    // unordered_map<Pair, int> mp;
    map<Pair, int> mp;
    const int dir[4][2] = {
        {0,-1}, {-1,-1}, {-1,1}, {0,1}
    };

    void vv2s(const vector<vector<char>>& seats, uint64_t& s1, uint64_t& s2) {
        s1 = 0;
        s2 = 0;
        int m = seats.size();
        int n = seats[0].size();
        for (int i = 0; i < m; ++i) {
            uint64_t v1 = 0;  // 8bits
            uint64_t v2 = 0;  // 8bits
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == 'o')
                    v1 |= 1<<j;
                else if (seats[i][j] == '.')
                    v2 |= 1<<j;
            }
            s1 |= v1 << (i*8);
            s2 |= v2 << (i*8);
        }
    }

    void getxy(const vector<vector<char>>& seats, int& x, int& y) {
        // DUMP(seats);
        int m = seats.size();
        int n = seats[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (seats[i][j] == '.') {
                    x = i;
                    y = j;
                    return;
                }
            }
        }
        assert(0);
    }

    int dfs(vector<vector<char>>& seats) {
        // DUMP("----dfs-----");
        uint64_t s1, s2;
        vv2s(seats, s1, s2);
        // DUMP(1, s1, s2);
        if (mp.find({s1,s2}) != mp.end())
            return mp[{s1,s2}];

        // 如果没有位置(.)了
        if (s2 == 0) {  // 没有位置可以坐了!
            // DUMP(2, s2);
            mp[{s1,s2}] = 0;
            return 0;
        }

        // DUMP(3);
        // 肯定有位置(.)，找第1个
        int x, y;  // 记录位置
        getxy(seats, x, y);

        // DUMP(4, x, y);
        // r1: 不坐这个位置
        seats[x][y] = '#';
        int r1 = dfs(seats);
        // DUMP(x, y, r1);
        seats[x][y] = '.';

        // DUMP(5, r1);
        // r2: 坐这个位置，看要看能不能坐!
        std::vector<std::pair<int,int>> vp;
        bool flag = false;
        seats[x][y] = 'o';
        int m = seats.size();
        int n = seats[0].size();
        for (int d = 0; d < 4; ++d) {
            int nx = dir[d][0] + x;
            int ny = dir[d][1] + y;
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (seats[nx][ny] == '#') continue;
            if (seats[nx][ny] == 'o') {  // 已经有人坐了作弊点, 那么这个位置(x,y)只能放弃
                flag = true;
                break;
            }
            vp.push_back({nx,ny});
            seats[nx][ny] = '#';
        }
        if (flag) {  // 不能坐!
            // DUMP(6, flag);
            mp[{s1,s2}] = r1;
            seats[x][y] = '.';
            return r1;
        }

        // DUMP(7);
        // 可以坐
        int r2 = 1 + dfs(seats);
        // DUMP(x, y, r2);
        for (auto& kv : vp)
            seats[kv.first][kv.second] = '.';
        seats[x][y] = '.';

        // DUMP(8, r2);
        int r = std::max(r1, r2);
        // DUMP(9, r);
        mp[{s1,s2}] = r;
        return r;
    }
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        // DUMP(0, m, n);
        int r = dfs(seats);
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

    vector<vector<string>> seats;
    lc::ParseArg(in[0], seats);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    vector<vector<char>> ss;
    for (int i = 0; i < seats.size(); ++i) {
        vector<char> v;
        for (int j = 0; j < seats[i].size(); ++j)
            v.push_back(seats[i][j][0]);
        ss.push_back(v);
    }
    DUMP(ss);

    Solution sol;
    auto r = sol.maxStudents(ss);
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
