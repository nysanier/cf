#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    int maximum69Number (int num) {
        std::vector<int> vec;
        while (num > 0) {
            auto d = num % 10;
            num /= 10;
            vec.push_back(d);
        }
        for (int i = vec.size()-1; i >= 0; --i) {
            if (vec[i] == 6) {
                vec[i] = 9;
                break;
            }
        }
        int r = 0;
        for (int i = vec.size()-1; i >= 0; --i) {
            r = r * 10 + vec[i];
        }
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
