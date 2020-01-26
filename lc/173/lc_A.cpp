#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    bool isHw(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] == s[j]) {
                ++i, --j;
                continue;
            }
            return false;
        }
        return true;
    }
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0)
            return 0;
        return isHw(s) ? 1 : 2;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    string s;
    lc::ParseArg(in[0], s);
    DUMP(s);

    Solution sol;
    auto r = sol.removePalindromeSub(s);
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
