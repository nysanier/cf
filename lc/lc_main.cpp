#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    bool func(vector<int>& arg0, int arg1, int arg2, int arg3) {
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

    vector<int> arg0; int arg1, arg2, arg3;
    lc::ParseArg(in[0], arg0);
    lc::ParseArg(in[1], arg1);
    lc::ParseArg(in[2], arg2);
    lc::ParseArg(in[3], arg3);
    DUMP(arg0, arg1, arg2, arg3);

    Solution sol;
    auto r = sol.func(arg0, arg1, arg2, arg3);
    DUMP(out, r);
    assert(out == to_string(r));
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
