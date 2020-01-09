#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    static const int N = 1e4 + 9;
    int sum[N];
    int maxd = -1;
    void travel(TreeNode* p, int d) {
        if (!p) return;
        if (d > maxd) maxd = d;
        sum[d] += p->val;
        travel(p->left, d+1);
        travel(p->right, d+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        std::fill(sum, sum+N, 0);
        travel(root, 0);
        return sum[maxd];
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    // vector<int> arg0; int arg1, arg2, arg3;
    // lc::ParseArg(in[0], arg0);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    // DUMP(arg0, arg1, arg2, arg3);
    TreeNode* root = nullptr;

    Solution sol;
    auto r = sol.deepestLeavesSum(root);
    DUMP(out, r);
    assert(out == to_string(r));
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
