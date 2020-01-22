#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> rv;
        for (int i = 0; i < ranges.size(); i++) {
            rv.push_back({i - ranges[i], i + ranges[i]});
        }
        sort(rv.begin(), rv.end());
        if (rv[0].first > 0) return -1;

        int pre = 0;
        int ind = 0;
        int res = 0;
        int right = -1;
        while (ind < rv.size()) {
            res++;
            right = pre;
            while (ind < rv.size() && rv[ind].first <= pre) {
                right = max(right, rv[ind].second);
                ind++;
            }
            if (ind >= rv.size()) break;
            if (right == pre) return -1;
            if (right >= n) return res;
            pre = right;
        }
        
        if (right < n) return -1;
        
        return res;
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
