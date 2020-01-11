#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
// 超时，那么需要剪枝
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        // std::set<std::string> st;
        std::unordered_set<std::string> st;
        for (int i = 0; i < text.size(); ++i) {
            auto ch = text[i];
            std::string::size_type p = i+1;
            for (;;) {
                auto p2 = text.find(ch, p);
                if (p2 == text.npos) break;
                int len1 = p2 - i;
                auto s1 = text.substr(i, len1);
                if (st.find(s1) != st.end()) {
                    p = p2 + 1;
                    continue;
                }
                int len2 = text.size() - p2;
                len2 = std::min(len2, len1);
                DUMP(i, ch, p, p2, len1, len2);
                if (len1 == len2) {
                    auto s2 = text.substr(p2, len2);
                    if (s1 == s2)
                        st.insert(s1);
                }
                p = p2 + 1;
            }
        }

        DUMP(st);
        return st.size();
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    string text;
    lc::ParseArg(in[0], text);
    DUMP(text);

    Solution sol;
    auto r = sol.distinctEchoSubstrings(text);
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
