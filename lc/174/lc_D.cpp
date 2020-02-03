#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

/*
每次跳[1,d]
且，跳的过程中，只能往低处跳
记忆化搜索即可!!
*/
// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 1000 + 9;
int f[N];
class Solution {
    int n;
    void init(vector<int>& arr, int d) {
        n = arr.size();
        memset(f, -1, sizeof(f));
    }
    int dfs(vector<int>& arr, int d, int x) {
        // DUMP(x);
        assert(x >= 0 && x < n);;
        if (f[x] >= 0) return f[x];
        int s = 0;
        for (int nx = x-1; nx >= x-d; --nx) {
            if (nx < 0) break;
            if (arr[nx] >= arr[x]) break;
            s = std::max(s, dfs(arr, d, nx));
        }
        for (int nx = x+1; nx <= x+d; ++nx) {
            if (nx >= n) break;
            if (arr[nx] >= arr[x]) break;
            s = std::max(s, dfs(arr, d, nx));
        }
        f[x] = s + 1;
        return f[x];
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        init(arr, d);
        int r = 0;
        for (int i = 0; i < n; ++i) {
            r = std::max(r, dfs(arr, d, i));
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

    vector<int> arr;
    int d;
    lc::ParseArg(in[0], arr);
    lc::ParseArg(in[1], d);
    DUMP(arr, d);

    Solution sol;
    auto r = sol.maxJumps(arr, d);
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
