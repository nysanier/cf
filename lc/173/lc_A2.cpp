#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 1000 + 9;
int vis[N];
class Solution {
    void init() {
        memset(vis, 0, sizeof(vis));
    }
public:
    int removePalindromeSub(string s) {
        // if (s.size() == 0)
        //     return 0;
        // if (s.size() == 1)
        //     return 1;

        init();
        int cnt = 0;
        int res = 0;
        while (cnt < s.size()) {
            res += 1;
            int i = 0, j = s.size()-1;
            while (i <= j) {
                for (; i < j; ++i)
                    if (!vis[i])
                        break;
                DUMP(vis[j], i<j, s[i]!=s[j]);
                for (; j > i; --j)
                    if (s[i] == s[j] && !vis[j])
                        break;
                DUMP(res, i, j, s[i], s[j]);
                if (i == j) {
                    vis[i] = 1;
                    cnt += 1;
                    // DUMP("--", cnt, i);
                    break;
                }
                if (i < j) {
                    vis[i] = 1;
                    vis[j] = 1;
                    cnt += 2;
                    ++i, --j;
                    // DUMP("--", cnt, i, j);
                }
            }
        }

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
