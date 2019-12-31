#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    static const int MOD = 1e9 + 7;
    static const int N = 1e2 + 9;
    int cnt[N][N];
    int sum[N][N];
    int dir[3][2] = {{1,0},{1,1},{0,1}};
    void init(vector<string>& board) {
        int sz = board.size();
        int i = sz-1;
        for (int j = i; j >= 0; --j) {
            if (board[i][j] == 'S') {
                sum[i][j] = 0;
                cnt[i][j] = 1;
                continue;
            }
            if (board[i][j] == 'X') {
                sum[i][j] = 0;
                cnt[i][j] = 0;
                continue;
            }
            sum[i][j] = 0;
            cnt[i][j] = 0;
            assert(j+1 < sz);
            if (cnt[i][j+1] == 0) {
                cnt[i][j] = 0;
            } else {
                sum[i][j] = board[i][j]-'0' + sum[i][j+1];
                cnt[i][j] = cnt[i][j+1];
            }
        }
        // DUMP(std::vector<int>(sum[sz-1],sum[sz-1]+sz));
        // DUMP(std::vector<int>(cnt[sz-1],cnt[sz-1]+sz));
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        init(board);
        int sz = board.size();
        for (int i = sz-2; i >= 0; --i) {
            for (int j = sz-1; j >= 0; --j) {
                if (board[i][j] == 'E') {
                    board[i][j] = '0';
                }
                if (board[i][j] == 'X') {
                    sum[i][j] = 0;
                    cnt[i][j] = 0;
                    continue;
                }
                sum[i][j] = 0;
                cnt[i][j] = 0;
                std::vector<std::pair<int, int>> pre;
                for (int k = 0; k < 3; ++k) {
                    auto i2 = i + dir[k][0];
                    auto j2 = j + dir[k][1];
                    // DUMP("try", i2, j2);
                    if (i2 >= 0 && i2 < sz && j2 >= 0 && j2 < sz && cnt[i2][j2] > 0) {
                        pre.push_back({i2,j2});
                        // DUMP("add", i2, j2);
                    }
                }
                for (auto& kv : pre) {
                    auto i2 = kv.first;
                    auto j2 = kv.second;
                    // DUMP(i2, j2);
                    int s2 = sum[i2][j2] + board[i][j]-'0';
                    if (s2 > sum[i][j]) {
                        sum[i][j] = s2;
                        cnt[i][j] = cnt[i2][j2];
                    } else if (s2 == sum[i][j]) {
                        cnt[i][j] = (cnt[i][j] + cnt[i2][j2]) % MOD;
                    }
                }
            }
            // DUMP(std::vector<int>(sum[i],sum[i]+sz), i);
            // DUMP(std::vector<int>(cnt[i],cnt[i]+sz), i);
        }

        return {sum[0][0], cnt[0][0]};
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    vector<string> board;
    lc::ParseArg(in[0], board);
    DUMP(board);

    Solution sol;
    auto r = sol.pathsWithMaxScore(board);
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
