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

const int N = 1e4 + 9;
// # define DUMP(args...)
using Pr = std::pair<int, int>;
std::vector<Pr> segs;
class Solution {
    void FixSegs(int p) {
        std::vector<Pr> s2; // (segs.begin()+cur+1, segs.end());
        for (auto& kv : segs) {
            if (kv.second < p) continue;
            if (kv.first < p) kv.first = p;
            if (kv.first == kv.second) continue;
            s2.push_back(kv);
        }
        DUMP(p, s2);
        segs.swap(s2);
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        for (int i = 0; i < n+1; ++i) {
            int a = i - ranges[i];
            int b = i + ranges[i];
            segs.push_back({a, b});
        }
        DUMP(segs);
        int r = 0;
        int p = 0;
        while (p < n) {
            FixSegs(p);
            std::sort(segs.begin(), segs.end());
            DUMP(p, segs);
            int cur = -1;
            for (int i = 0; i < segs.size(); ++i) {
                if (cur == -1) {
                    if (segs[i].first > p) {  // 这点无法覆盖
                        DUMP("failed", i, segs[i]);
                        return -1;
                    }
                    else {
                        cur = i;
                        continue;
                    }
                }

                if (segs[i].first > segs[cur].first) {  // 后面的线段无法覆盖p了，选当前的
                    break;
                }

                cur = i;
            }
            if (cur == -1) {
                DUMP("failed", cur);
                return -1;
            }
            if (segs[cur].first == segs[cur].second) {
                DUMP("failed", cur, segs[cur]);
                return -1;
            }

            // 取cur, 放弃cur前面的线段, 并继续统计后面的线段
            r += 1;
            DUMP(p, cur, segs[cur]);
            p = segs[cur].second;  // 下一个需要覆盖的位置
        }
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
