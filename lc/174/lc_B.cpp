#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> ump;
        for (auto a : arr) ump[a] += 1;
        vector<int> vec;
        for (auto& kv : ump) vec.push_back(-kv.second);
        int n = arr.size();
        int c = 0;
        std::sort(vec.begin(), vec.end());
        int i = 0;
        for (; i < vec.size() && c < n/2; ++i) {
            c += -vec[i];
        }
        return i;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    vector<int> arr;
    lc::ParseArg(in[0], arr);
    DUMP(arr);

    Solution sol;
    auto r = sol.minSetSize(arr);
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
