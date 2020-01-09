#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    // true: even
    bool check(int n) {
        int s = 0;
        while (n > 0) {
            s += 1;
            n /= 10;
        }
        return s % 2 == 0;
    }
public:
    int findNumbers(vector<int>& nums) {
        int r = 0;
        for (auto n : nums) {
            if (check(n)) r += 1;
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

    vector<int> nums;
    lc::ParseArg(in[0], nums);
    DUMP(nums);

    Solution sol;
    auto r = sol.findNumbers(nums);
    DUMP(out, r);
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
