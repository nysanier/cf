#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // if (restaurants.size() == 0)
        vector<pair<int, int>> res;
        for (auto& a : restaurants) {
            if (veganFriendly && !a[2])
                continue;
            if (maxPrice < a[3]) continue;
            if (maxDistance < a[4]) continue;
            res.push_back({-a[1], -a[0]});
        }
        std::sort(res.begin(), res.end());
        vector<int> r;
        for (auto& kv : res)
            r.push_back(-kv.second);
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

    vector<vector<int>> restaurants;
    int veganFriendly;
    int maxPrice;
    int maxDistance;
    lc::ParseArg(in[0], restaurants);
    lc::ParseArg(in[1], veganFriendly);
    lc::ParseArg(in[2], maxPrice);
    lc::ParseArg(in[3], maxDistance);
    DUMP(restaurants, veganFriendly, maxPrice, maxDistance);

    Solution sol;
    auto r = sol.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);
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
