#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    string freqAlphabets(string s) {
        std::string r;
        for (int i = s.size()-1; i >= 0;) {
            if (s[i] == '#') {
                int a = s[i-2] - '0';
                int b = s[i-1]-'0';
                int v = 10 * a + b;  // 1 - 26
                char c = 'a' + v-1;
                // DUMP("#", i, a, b, v, c);
                r.push_back(c);
                i -= 3;
            } else {
                int v = s[i]-'1';
                char c = 'a' + v;
                // DUMP(i, v, c);
                r.push_back(c);
                i -= 1;
            }
        }
        std::reverse(r.begin(), r.end());
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

    string s;
    lc::ParseArg(in[0], s);
    DUMP(s);

    Solution sol;
    auto r = sol.freqAlphabets(s);
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
