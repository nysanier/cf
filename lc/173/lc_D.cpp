#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// 贪心
// 1. 设线段{[ai,bi]...}
// 2. 根据ai,bi来排序，ai小的排前面, 相同ai,那么bi小的排前面
// 针对某个点p, 如果找一条覆盖p, 且最长的线段(不计算p前面的长度), 这条线段最右端是q
// 取这条线段，并设置p=q, 并移除所有右端小于q的线段
// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 1e4 + 9;
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if (jobDifficulty.size() < d)
            return -1;

        int cnt = jobDifficulty.size() - d;
        vector<pair<int, int>> vec;
        int sum = 0;
        for (int i = 0; i < jobDifficulty.size(); ++i) {
            sum += jobDifficulty[i];
            vec.push_back({-jobDifficulty[i], i});
        }
        std::sort(vec.begin(), vec.end());
        while (cnt > 0) {
            
        }
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    // int n{5};
    // vector<int> ranges{3,4,1,1,0,0};
    // int n{8};
    // vector<int> ranges{4,0,0,0,0,0,0,0,4};
    // int n{7};
    // vector<int> ranges{1,2,1,0,2,1,0,1};
    int n{3};
    vector<int> ranges{0,0,0,0};
    // int n{5};
    // vector<int> ranges{3,4,1,1,0,0};
    // lc::ParseArg(in[0], n);
    // lc::ParseArg(in[0], ranges);
    DUMP(n, ranges);

    Solution sol;
    auto r = sol.minTaps(n, ranges);
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
