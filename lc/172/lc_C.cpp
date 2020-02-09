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
    int travel(TreeNode*& pp, TreeNode* p, int target) {
        if (!p) return 0;
        if (!p->left && !p->right) {  // leaf
            if (p->val == target) {
                pp = nullptr;
                return 1;
            }
        }
        return travel(p->left, p->left, target) + travel(p->right, p->right, target);
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        for (;;) {
            auto v = travel(root, root, target);
            if (v == 0) break;
        }
        return root;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    vector<string> in;
    std::string out;
    lc::Read(in, out);

    TreeNode* root = nullptr;
    int target = 0;
    // lc::ParseArg(in[0], n);
    // lc::ParseArg(in[1], connections);
    DUMP(root, target);

    Solution sol;
    auto r = sol.removeLeafNodes(root, target);
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
