#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    bool Check(int x) {
        if (x == 0) return false;
        if (x < 10) return true;
        while (x > 0) {
            auto d = x % 10;
            if (d == 0) return false;
            x /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i) {
            auto k = n - i;
            if (Check(i) && Check(k)) {
                return {i,k};
            }
        }
        assert(0);
        return {0,0};
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    int n;
    lc::ParseArg(in[0], n);
    DUMP(n);

    Solution sol;
    auto r = sol.getNoZeroIntegers(n);
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
