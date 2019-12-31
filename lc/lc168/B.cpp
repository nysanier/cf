#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    std::map<int, int> mp;
    void init(vector<int>& nums) {
        for (auto n : nums)
            mp[n] += 1;
    }
    bool remove(int k) {
        // 最小有几个移除几个
        assert(mp.size() > 0);
        auto s = *mp.begin();
        mp.erase(mp.begin());
        for (int i = 1; i <= k-1; ++i) {
            auto it = mp.find(s.first+i);
            if (it == mp.end() || it->second < s.second)
                return false;
            it->second -= s.second;
            if (it->second == 0)
                mp.erase(it);
        }
        return true;
    }
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        init(nums);
        while (!mp.empty()) {
            // DUMP(mp);
            if (!remove(k)) return false;
        }
        return true;
    }
};
}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    vector<int> nums; int k;
    lc::ParseArg(in[0], nums);
    lc::ParseArg(in[1], k);
    DUMP(nums, k);

    Solution sol;
    auto r = sol.isPossibleDivide(nums, k);
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
