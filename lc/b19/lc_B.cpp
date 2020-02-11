#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int> s(arr.begin(), arr.end());
        for (int i = 1; i < s.size(); ++i)
            s[i] += s[i-1];
        int r = 0;
        int t = threshold * k;
        for (int i = 0; i < arr.size(); ++i) {
            auto y = i + k - 1;
            if (y >= arr.size()) continue;
            int s2 = s[y];
            auto x = i - 1;
            int s1 = 0;
            if (x >= 0) s1 = s[x];
            if (s2 - s1 >= t) r += 1;
        }
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

    #define FUNC func
    #define ARGS arg0, arg1, arg2, arg3
    int arg0;
    int arg1;
    int arg2;
    int arg3;
    lc::ParseArg(in[0], arg0);
    lc::ParseArg(in[1], arg1);
    lc::ParseArg(in[2], arg2);
    lc::ParseArg(in[3], arg3);
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
