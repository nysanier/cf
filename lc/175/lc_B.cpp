#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    int minSteps(string s, string t) {
        // DUMP("abcdsf\n");
        std::map<int, int> mps, mpt;
        for (auto c : s) mps[c] += 1;
        for (auto c : t) mpt[c] += 1;
        int r = 0;
        for (auto& kv : mpt) {
            if (kv.second <= mps[kv.first]) continue;
            r += kv.second - mps[kv.first];
        }
        return r;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    // vector<string> in;
    // std::string out;
    // lc::Read(in, out);

    // 为什么读不进来？
    string s = "bab", t = "aba";
    // string s, t;
    // lc::ParseArg(in[0], s);
    // lc::ParseArg(in[1], t);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    DUMP(s, t);

    Solution sol;
    auto r = sol.minSteps(s, t);
    // DUMP(out, r);
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


/*
5

示例 1：

输出：s = "bab", t = "aba"
输出：1
提示：用 'b' 替换 t 中的第一个 'a'，t = "bba" 是 s 的一个字母异位词。
示例 2：

输出：s = "leetcode", t = "practice"
输出：5
提示：用合适的字符替换 t 中的 'p', 'r', 'a', 'i' 和 'c'，使 t 变成 s 的字母异位词。
示例 3：

输出：s = "anagram", t = "mangaar"
输出：0
提示："anagram" 和 "mangaar" 本身就是一组字母异位词。 
示例 4：

输出：s = "xxyyzz", t = "xxyyzz"
输出：0
示例 5：

输出：s = "friend", t = "family"
输出：4


*/
