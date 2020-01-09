#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    static const int N = 3e4 + 9;
    int s[N];
    void init(vector<int>& arr) {
        int v = 0;
        for (int i = 0; i < arr.size(); ++i) {
            v ^= arr[i];
            s[i] = v;
        }
    }
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        init(arr);
        vector<int> r;
        for (auto& ab : queries) {
            // 9 * 10^8 超时!!!
            // int v = 0;
            // for (int i = ab[0]; i <= ab[1]; ++i) {
            //     v ^= arr[i];
            // }

            int v = 0;
            if (ab[0] == 0) v = s[ab[1]];
            else v = s[ab[1]] ^ s[ab[0]-1];
            r.push_back(v);
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

    vector<int> arr;
    vector<vector<int>> queries;
    lc::ParseArg(in[0], arr);
    lc::ParseArg(in[1], queries);
    DUMP(arr, queries);

    Solution sol;
    auto r = sol.xorQueries(arr, queries);
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
