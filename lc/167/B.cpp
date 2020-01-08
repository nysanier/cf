#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        std::set<int> all {
            // 1,2,3,4,5,6,7,8,9,
            // 12,23,34,45,56,67,78,89,
            // 123,234,345,456,567,678,789,
            // 1234,
            // ...
            // 12345678, 223456789
            // 123456789
        };
        for (int k = 1; k <= 9; ++k) {  // 位数，控制行
            for (int i = 1; i <= 10-k; ++i) {  // 个数，控制列
                int v = 0;
                for (int j = 0; j < k; ++j)
                    v = 10 * v + (i+j);  // 当前位
                all.insert(v);
            }
        }
        auto it1 = all.lower_bound(low);  // >= low
        auto it2 = all.upper_bound(high);  // > high
        std::vector<int> r;
        for (auto it = it1; it != it2; ++it)
            r.push_back(*it);
        return r;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    // lc::Read(in, out);

    // int low = 100;
    // int high = 300;
    int low = 1000;
    int high = 13000;
    // lc::ParseArg(in[0], low);
    // lc::ParseArg(in[1], high);
    DUMP(low, high);

    Solution sol;
    auto r = sol.sequentialDigits(low, high);
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
