#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    void Split(std::vector<std::string>& out, const std::string& str, const std::string& sep) {
        std::string::size_type p = 0;
        while (p < str.size()) {
            auto p2 = str.find(sep, p);
            if (p2 == str.npos)
                p2 = str.size();
            auto v = str.substr(p, p2-p);
            if (!v.empty())
                out.push_back(v);
            p = p2 + sep.size();
        }
    }
public:
    vector<string> printVertically(string s) {
        std::vector<std::string> vecs;
        Split(vecs, s, " ");
        DUMP(vecs);
        int maxlen = 0;
        for (auto& v : vecs)
            maxlen = std::max(maxlen, int(v.size()));
        DUMP(maxlen);
        std::vector<std::string> res(maxlen, std::string(vecs.size(), ' '));
        for (int k = 0; k < vecs.size(); ++k) {
            for (int i = 0; i < vecs[k].size(); ++i) {
                res[i][k] = vecs[k][i];
            }
        }
        DUMP(res);

        for (auto& str : res) {
            auto p = str.find_last_not_of(' ');
            str.resize(p+1);
        }
        DUMP(res);
        return res;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    string s = "CONTEST IS COMING";
    // lc::ParseArg(in[0], s);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    DUMP(s);

    Solution sol;
    auto r = sol.printVertically(s);
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
