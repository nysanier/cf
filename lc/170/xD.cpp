#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    static const int N = 500 + 9;
    // int vis[N][N];
    int a[N][N];
    string str;
    void init(string s) {
        str = s;
        memset(a, -1, sizeof(a));
    }
    int f(int i, int j) {
        auto sij = str.substr(i, j-i+1);
        // DUMP("check", i, j, sij);
        assert(i <= j);
        if (a[i][j] >= 0) return a[i][j];
        if (i == j) {
            a[i][j] = 0;
            // DUMP("  i==j", a[i][j]);
            return a[i][j];
        }
        if (i+1 == j) {
            if (str[i] == str[j]) a[i][j] = 0;
            else a[i][j] = 1;
            // DUMP("  i+1==j", a[i][j]);
            return a[i][j];
        }
        if (str[i] == str[j])
            return f(i+1, j-1);
        auto m1 = f(i+1, j) + 1;
        auto m2 = f(i, j-1) + 1;
        auto m = std::min(m1, m2);
        a[i][j] = m;
        // DUMP("  else", m1, m2, m, a[i][j]);
        return m;
    }
public:
    int minInsertions(string s) {
        init(s);
        auto r = f(0, s.size()-1);
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
    auto r = sol.minInsertions(s);
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
