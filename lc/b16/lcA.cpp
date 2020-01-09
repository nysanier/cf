#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// 居然超时, 1e8都执行不了吗？
// # define DUMP(args...)
class Solution {
    vector<int> res;
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::set<int> s;
        for (int i = arr.size()-1; i >= 0; --i) {
            if (i == arr.size()-1) {
                res.push_back(-1);
            }
            else {
                res.push_back(*--s.end());
            }
            s.insert(arr[i]);
        }
        std::reverse(res.begin(), res.end());
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

    vector<int> arr;
    lc::ParseArg(in[0], arr);
    DUMP(arr);

    Solution sol;
    auto r = sol.replaceElements(arr);
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
