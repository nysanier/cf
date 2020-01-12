#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

const int N = 26 + 3;
int v[N][N][N][N];
// # define DUMP(args...)
class Solution {
    using Pr = std::pair<int, int>;
    // #define MAP std::unordered_map
    #define MAP std::map
    MAP<int, Pr> pos;  // 'A' -> position{0, 0}
    MAP<Pr, int> dis;  // {'A','B'} -> dAB
    std::string w;
    void init(const string& word) {
        memset(v, -1, sizeof(v));
        w = word;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 6; ++j)
                pos['A'+i*6+j] = {i,j};
        pos['Y'] = {4,0};
        pos['Z'] = {4,1};

        for (int a = 'A'; a <= 'Z'; ++a) {
            for (int b = 'A'; b <= 'Z'; ++b) {
                auto p1 = pos[a];
                auto p2 = pos[b];
                // 'A'-'Z' -> 1-26
                dis[{a-'A'+1,b-'A'+1}] = abs(p1.first-p2.first) + abs(p1.second-p2.second);
            }
        }
        // auto dAA = dis[{'A','A'}];  // 0
        // auto dCA = dis[{'C','A'}];  // 2
        // auto dKE = dis[{'K','E'}];  // 1
        // auto dHA = dis[{'H','A'}];  // 2
        // auto dAY = dis[{'A','Y'}];  // 4
        // DUMP(dAA);
        // DUMP(dCA);
        // DUMP(dKE);
        // DUMP(dHA);
        // DUMP(dAY);
    }
    int f(int k, int n, int p1, int p2, int a) {
        if (k >= n) return 0;
        int b = w[k] - 'A' + 1;
        if (v[p1][p2][a][b] != -1)  // 状态表达式有问题!!!
            return v[p1][p2][a][b];
        int d1 = (p1>0 ? dis[{p1,b}] : 0);
        auto x1 = f(k+1, n, b, p2, b);  // 用p1
        int d2 = (p2>0 ? dis[{p2,b}] : 0);
        auto x2 = f(k+1, n, p1, b, b);  // 用p2
        auto m = std::min(d1+x1, d2+x2);
        v[p1][p2][a][b] = m;
        return m;
    }
public:
    int minimumDistance(string word) {
        init(word);
        int a = w[0] - 'A' + 1;
        // auto r = f(1, word.size(), a, 0, a);
        auto r = f(1, word.size(), 0, a, a);
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
