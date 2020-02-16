#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// 应该按照截止时间优先，来排序
// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
int cur = 0;
class Solution {
    using Pair = std::pair<int, int>;
public:
    int maxEvents(vector<vector<int>>& events) {
        vector<Pair> e;
        for (auto& vec : events)
            e.push_back({vec[0], vec[1]});

        int r = 0;
        cur = 0;
        // DUMP(e);
        // n ^ 2, 难道要用到heap！ 
        // TODO 为什么超时
        for (int i = 0; i < e.size(); ++i) {
            auto cmp = [](const Pair& a, const Pair& b){
                int ka = std::max(a.first, cur+1);
                int kb = std::max(b.first, cur+1);
                return Pair{ka, a.second} < Pair{kb, b.second};
            };
            std::nth_element(e.begin()+i, e.begin()+i, e.end(), cmp);
            auto& kv = *(e.begin()+i);
            // DUMP(kv);
            if (kv.second <= cur) {
                // DUMP("  ignore");
                continue;
            }
            r += 1;
            cur = std::max(kv.first, cur+1);
            // DUMP("  pick", cur);
        }

        // vector<Pair> e;
        // for (auto& vec : events)
        //     e.push_back({vec[1], vec[0]});
        // std::sort(e.begin(), e.end());
        // int r = 0;
        // cur = 0;
        // for (auto& kv : e) {
        //     if (kv.second <= cur) {
        //         DUMP("  ignore");
        //         continue;
        //     }
        //     r += 1;
        //     cur = std::max(kv.first, cur+1);
        //     DUMP("  pick", cur);
        // }
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

    #define FUNC maxEvents
    #define ARGS events
    vector<vector<int>> events;
    lc::ParseArg(in[0], events);
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
