#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// 每个时间点，选择符合条件，且截止时间最早的哪个event
//   用一个heap保存当前符合条件的所有event
//   c++还是比python效率高很多！！
// 0 分钟	最多可以参加的会议数目	通过	372 ms	cpp
// 2 小时，49 分钟	最多可以参加的会议数目	通过	1356 ms	python3
// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
int cur = 0;
class Solution {
    using Pair = std::pair<int, int>;
public:
    int maxEvents(vector<vector<int>>& events) {
        // vector<vector<int>> 等同于 vector<pair<int,int>> 的排序效果
        std::sort(events.begin(), events.end());
        // 默认是大堆！这里要小堆！
        priority_queue<int, vector<int>, greater<int>> pq;
        int idx = 0;
        int r = 0;
        for (int cur = 1; cur <= 1e5; ++cur) {
            for (; idx < events.size(); ++idx) {
                if (events[idx][0] > cur)
                    break;
                pq.push(events[idx][1]);
            }
            while (!pq.empty()) {
                auto t = pq.top(); pq.pop();
                if (t < cur) continue;  // 无效了
                r += 1;
                break;
            }
        }
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
