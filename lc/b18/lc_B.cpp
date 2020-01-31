#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if (n == 1) {
            return "";
        }
        int idx = -1;
        for (int i = 0; i < (n+1)/2; ++i) {
            if (palindrome[i] != 'a') {
                idx = i;
                break;
            }
        }
        DUMP(palindrome, n, idx);
        if (n % 2 == 1 && idx == (n+1)/2-1) {
            palindrome[n-1] = 'b';
        } else if (idx == -1) {
            palindrome[n-1] = 'b';
        } else {
            palindrome[idx] = 'a';
        }
        return palindrome;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    string palindrome;
    lc::ParseArg(in[0], palindrome);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    DUMP(palindrome);

    Solution sol;
    auto r = sol.breakPalindrome(palindrome);
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
