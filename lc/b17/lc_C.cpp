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
    int travel(TreeNode* p, TreeNode* p1, TreeNode* p2) {
        if (!p) return 0;
        int v = 0;
        if (p1 && p2 && p2->val % 2 == 0) v = p->val;
        return v + travel(p->left, p, p1) + travel(p->right, p, p1);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        auto r = travel(root, nullptr, nullptr);
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

    TreeNode* root = nullptr;
    // lc::ParseArg(in[0], arg0);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    // DUMP(arg0, arg1, arg2, arg3);

    Solution sol;
    auto r = sol.sumEvenGrandparent(root);
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
