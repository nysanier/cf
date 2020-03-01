#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // int n = votes.size();  // 投票者数
        int m = votes[0].size();  // 候选人数
        vector<vector<int>> vv(26, vector<int>(m));
        // DUMP(vv);
        for (auto& str : votes) {
            // DUMP(str);
            for (int i = 0; i < m; ++i) {
                int ch = str[i];
                int idx = ch - 'A';
                // DUMP(ch, idx, i);
                vv[idx][i] -= 1;
            }
        }
        // DUMP(vv);
        vector<int> v0(m);
        set<vector<int>> st;
        for (int i = 0; i < 26; ++i) {
            if (vv[i] == v0) continue;

            vv[i].push_back(i);  // 编号
            st.insert(vv[i]);      
        }
        // DUMP(st);
        string r;
        for (auto& vec : st) {
            int last = vec[vec.size()-1];  // 取编号
            r += (char('A' + last));
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

    #define FUNC rankTeams
    #define ARGS arg0
    vector<string> arg0;
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
