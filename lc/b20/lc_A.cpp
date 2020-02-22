#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    int count(int n) {
        int r = 0;
        while (n > 0) {
            if (n & 1) r += 1;
            n >>= 1;
        }
        return r;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        std::vector<std::pair<int, int>> vec;
        for (auto n : arr)
            vec.push_back({count(n), n});
        std::sort(vec.begin(), vec.end());
        std::vector<int> r;
        for (auto& kv : vec)
            r.push_back(kv.second);
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

    #define FUNC sortByBits
    #define ARGS arg0
    vector<int> arg0;
    // int arg1;
    // int arg2;
    // int arg3;
    lc::ParseArg(in[0], arg0);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
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
