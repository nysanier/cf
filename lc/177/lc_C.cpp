#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// 找最大因子, <=2^16
// 解题思路 均值不等式可知 a+b>=2*sqrt(a*b)
//   两个数和固定的情况下，两数越接近，他们的乘积越大。
//   所以，直接先开根号，然后递减遍历，当数字可以被sum整除，就可以直接返回了，不需要继续遍历，这个时候得到的乘积，一定是最大的。
//   最后只要比较num+1得到的因子和num+2得到的因子，差的绝对值较小的那个即可
// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    // 找最大因子, <=2^16
    vector<int> getFac(int n) {
        int sq = ceil(sqrt(n));
        for (int i = sq; i > 0; --i) {
            if (n % i == 0)
                return {i, n/i};
        }
        // 不可能, 每个数都可以被1除
        assert(0);
        return {0,0};
    }
public:
    vector<int> closestDivisors(int num) {
        auto x = getFac(num+1);
        auto y = getFac(num+2);
        std::sort(x.begin(), x.end());
        std::sort(y.begin(), y.end());
        if (x[1]-x[0] < y[1]-y[0])
            return x;
        else
            return y;
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

    #define FUNC closestDivisors
    #define ARGS arg0
    int arg0;
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
