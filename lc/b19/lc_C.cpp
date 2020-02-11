#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h1 = 360.0 / 12;
        double h2 = h1 / 60;
        double m1 = 360.0 / 60;
        if (hour == 12) hour = 0;
        auto d = abs(h1*hour + h2*minutes - m1*minutes);
        if (d > 180.0)
            d = 360 - d;
        return d;
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

    #define FUNC func
    #define ARGS arg0, arg1, arg2, arg3
    int arg0;
    int arg1;
    int arg2;
    int arg3;
    lc::ParseArg(in[0], arg0);
    lc::ParseArg(in[1], arg1);
    lc::ParseArg(in[2], arg2);
    lc::ParseArg(in[3], arg3);
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
