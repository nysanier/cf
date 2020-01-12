#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    int minFlips(int a, int b, int c) {
        auto d = a | b;
        auto d2 = a & b;
        DUMP(d, d2);
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            auto x = d & 1;  // 0->0,1->1
            auto y = d2 & 1;
            auto z = c & 1;
            DUMP(i, x, y, z);
            if (x == z) {
                d >>= 1;
                d2 >>= 1;
                c >>= 1;
                continue;
            }

            if (z == 0) {
                if (y == 1) ans += 2;
                else ans += 1;
            } else {  // z == 1
                ans += 1;
            }
            d >>= 1;
            d2 >>= 1;
            c >>= 1;
        }
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

    int a = 8, b = 3, c = 5;
    // lc::ParseArg(in[0], arg0);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    DUMP(a, b, c);

    Solution sol;
    auto r = sol.minFlips(a, b, c);
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
