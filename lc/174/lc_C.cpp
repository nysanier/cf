#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

/*
每个节点如果有子节点，那么就有这么条边，断开这条边，就需要计算一次
每个节点都去保存，自己+所有子孙节点的和，这样断边的时候可以快速计算乘积。
根节点的和就是整棵树的和，最大值5e8

*/
// -------------------------------------------------
namespace {
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// # define DUMP(args...)
const int N = 5e4 + 9;
const int MOD = 1e9 + 7;
class Solution {
    using ll = long long;
    int s{0};
    ll a{1123456789};
    unordered_map<void*, int> ump;

    int sum(TreeNode* p) {
        if (!p) return 0;
        int v = p->val + sum(p->left) + sum(p->right);
        ump[p] = v;  // 每个节点及其子孙节点的和
        return v;
    }
    void dfs(TreeNode* p) {
        if (!p) return;
        if (!p->left && !p->right) return;  // 叶子节点不用断边
        // 至少有一个子节点
        if (p->left) {
            ll v = ump[p->left];
            v = std::max(v, s - v);
            a = std::min(a, v);
            dfs(p->left);
        }
        if (p->right) {
            ll v = ump[p->right];
            v = std::max(v, s - v);
            a = std::min(a, v);
            dfs(p->right);
        }
    }
public:
    int maxProduct(TreeNode* root) {
        s = sum(root);
        dfs(root);
        ll c = (a%MOD) * ((s-a)%MOD);
        ll r = c % MOD;
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
    DUMP(root);

    Solution sol;
    auto r = sol.maxProduct(root);
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
