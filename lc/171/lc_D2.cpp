#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

const int N = 300 + 9;
uint32_t a[N][30][30];
// # define DUMP(args...)
class Solution {
    using Pr = std::pair<int, int>;
    // #define MAP std::unordered_map
    #define MAP std::map
    MAP<int, Pr> pos;  // 'A' -> position{0, 0}
    MAP<Pr, int> dis;  // {'A','B'} -> dAB
    std::string w;
    void init(const string& word) {
        // memset(a, 0xff, sizeof(a));
        for (int k = 0; k < N; ++k)
            for (int i = 0; i < 26; ++i)
                for (int j = 0; j < 26; ++j)
                    a[k][i][j] = 1e9;
        for (int i = 0; i < 26; ++i) {
            int r = i / 6;
            int c = i % 6;
            pos[i] = {r, c};
        }
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dis[{i,j}] = abs(pos[i].first-pos[j].first) + abs(pos[i].second-pos[j].second);
            }
        }
    }
public:
    int minimumDistance(string word) {
        init(word);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                // 这个初始化为啥？如何计算a[0][A][B] a[0][x][y] -> a[1][A][y] -> a[2][A][B]
                a[0][i][j] = 0;
            }
        }

        for (int k = 0; k < word.size(); ++k) {
            int v = word[k] - 'A';
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    // 这个状态和递推还不是特别明白
                    a[k+1][v][j] = std::min(a[k+1][v][j], a[k][i][j] + dis[{i,v}]);
                    a[k+1][i][v] = std::min(a[k+1][i][v], a[k][i][j] + dis[{j,v}]);
                }
            }
        }

        uint32_t ans = 1e9;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans = std::min(ans, a[word.size()][i][j]);
                // DUMP(i, j, ans);
            }
        }
        // col(ans);
        return ans;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    string word;
    lc::ParseArg(in[0], word);
    DUMP(word);

    Solution sol;
    auto r = sol.minimumDistance(word);
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
