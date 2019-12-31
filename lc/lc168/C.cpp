#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    map<string, int> s2n;
    map<int, string> res;
    void minus(map<char, int>& cur, char c) {
        auto it = cur.find(c);
        assert(it != cur.end());
        it->second -= 1;
        if (it->second == 0)
            cur.erase(it);
    }
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        for (int k = minSize; k <= maxSize; ++k) {
            map<char, int> cur;
            for (int i = 0; i < k; ++i)
                cur[s[i]] += 1;
            if (cur.size() <= maxLetters) {  // check
                auto sub = s.substr(0, k);
                s2n[sub] += 1;
            }
            int len = s.size() - k;
            // DUMP(k, len);
            for (int i = 1; i <= len; ++i) {
                if (s[i+k-1] != s[i-1]) {
                    minus(cur, s[i-1]);
                    cur[s[i+k-1]] += 1;
                }
                if (cur.size() <= maxLetters) {  // check
                    auto sub = s.substr(i, k);
                    s2n[sub] += 1;
                }
            }
        }

        // DUMP(s2n);
        for (auto& kv : s2n)
            res[-kv.second] = kv.first;
        // DUMP(res);
        if (res.empty())
            return 0;
        return -res.begin()->first;
    }
};
}
void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    lc::Readin(in);

    string s; int maxLetters; int minSize; int maxSize;
    lc::ParseArg(in[0], s);
    lc::ParseArg(in[1], maxLetters);
    lc::ParseArg(in[2], minSize);
    lc::ParseArg(in[3], maxSize);
    DUMP(s, maxLetters, minSize, maxSize);

    Solution sol;
    auto r = sol.maxFreq(s, maxLetters, minSize, maxSize);
    DUMP(r);
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
