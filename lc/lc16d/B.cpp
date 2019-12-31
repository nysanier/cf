#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    int cal(vector<int>& arr, int g) {
        int sum = 0;
        for (auto v : arr) {
            if (v > g) sum += g;
            else sum += v;
        }
        return sum;
    }
    int findGt(vector<int>& arr, int t, int l, int r) {
        while (l < r) {
            auto h = (l + r) / 2;
            if (cal(arr, h) <= t) {
                l = h + 1;
            } else {
                r = h;
            }
        }
        return l;
    }
public:
    int findBestValue(vector<int>& arr, int target) {
        if (arr.size() == 1) {
            if (arr[0] > target) {
                return target;
            } else {
                return arr[0];
            }
        }

        std::sort(arr.begin(), arr.end());
        int mid1 = target / arr.size();
        int mid2 = (target + arr.size()-1) / arr.size();
        auto m1 = std::min(*arr.begin(), mid1);
        auto m2 = std::max(*--arr.end(), mid2);
        auto g2 = findGt(arr, target, m1, m2);
        auto g1 = g2-1;
        auto s2 = cal(arr, g2);
        auto s1 = cal(arr, g1);
        auto r2 = s2 - target;
        auto r1 = target - s1;
        DUMP(g1, g2, s1, s2, r1, r2);
        if (r1 <= r2) {
            return g1;
        } else {
            return g2;
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

    vector<int> arr; int target;
    lc::ParseArg(in[0], arr);
    lc::ParseArg(in[1], target);
    DUMP(arr, target);

    Solution sol;
    auto r = sol.findBestValue(arr, target);
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
