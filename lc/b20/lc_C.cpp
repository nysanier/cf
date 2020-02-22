#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 5e4 + 9;
int f[N][3];
class Solution {
    void init(const string& s) {
        memset(f, 0, sizeof(f));
        int a = 0;
        int b = 0;
        int c = 0;
        int n = 0;
        for (auto ch : s) {
            if (ch == 'a') a += 1;
            else if (ch == 'b') b += 1;
            else c += 1;
            f[n][0] = a;
            f[n][1] = b;
            f[n][2] = c;
            n += 1;
        }
        // for (int i = 0; i < s.size(); ++i) {
        //     vector<int> fv(f[i], f[i] + 3);
        //     DUMP(i, fv);
        // }
    }
public:
    int numberOfSubstrings(string s) {
        init(s);
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            int l = i;
            int r = s.size() - 1;
            // DUMP("---", i, l, r);
            if (r - l < 2) continue;
            int a = 0, b = 0, c = 0;
            if (l > 0) {
                a = f[l-1][0];
                b = f[l-1][1];
                c = f[l-1][2];
            }
            // 至少有一个字母没有, 那么就结束
            if (f[r][0] - a < 1) continue;
            if (f[r][1] - b < 1) continue;
            if (f[r][2] - c < 1) continue;
            // 二分找到最小的r位置
            while (l < r) {
                auto h = (l + r) / 2;
                auto x = f[h][0];
                auto y = f[h][1];
                auto z = f[h][2];
                // DUMP(x, y, z, a, b, c);
                if (x - a < 1 || y - b < 1 || z - c < 1) {
                    l = h + 1;
                } else {
                    r = h;
                }
                // DUMP("   ", h, l, r);
            }
            auto v = s.size() - r;
            // DUMP(i, v, l, r);
            ret += v;
        }
        return ret;
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

    #define FUNC numberOfSubstrings
    #define ARGS arg0
    string arg0;
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
