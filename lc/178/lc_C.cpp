#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// # define DUMP(args...)
class Solution {
    ListNode* head_ = nullptr;
    bool dfs(ListNode* pl, TreeNode* pt, int k) {
        // 检查结束
        if (!pl)
            return true;
        if (!pt)
            return false;

        DUMP("current", pl->val, pt->val, k);

        // 已经找到了head, 继续往下find
        if (k > 0 && pl->val && pt->val) {
            DUMP("check-left", pt->left);
            if (dfs(pl->next, pt->left, k+1)) {
                DUMP("check-ok", pt->left);
                return true;
            }
            DUMP("check-right", pt->right);
            if (dfs(pl->next, pt->right, k+1)) {
                DUMP("check-ok", pt->right);
                return true;
            }
        }

        // 首次找到head
        if (head_->val == pt->val) {
            DUMP("first-left", pt->left);
            if (dfs(head_->next, pt->left, 1)) {
                DUMP("first-ok", pt->left);
                return true;
            }
            DUMP("first-right", pt->right);
            if (dfs(head_->next, pt->right, 1)) {
                DUMP("first-ok", pt->right);
                return true;
            }
        }

        // 不满足要求, 且没有找到head
        DUMP("find-left", pt->left);
        if (dfs(head_, pt->left, 0)) {
            DUMP("find-ok", pt->left);
            return true;
        }
        DUMP("find-right", pt->right);
        if (dfs(head_, pt->right, 0)) {
            DUMP("find-ok", pt->right);
            return true;
        }

        DUMP("find-none");
        return false;
    }
    void travel(TreeNode* p, int k) {
        if (!p)
            return;
        DUMP(k, p->val);
        travel(p->left, k+1);
        travel(p->right, k+1);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // travel(root, 0);
        head_ = head;
        auto r = dfs(head, root, 0);
        return r;
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

    #define FUNC isSubPath
    #define ARGS head, root
    ListNode* head = nullptr;
    // {
    //     auto p1 = new ListNode(1);
    //     auto p10 = new ListNode(10);
    //     p1->next = p10;

    //     head = p1;
    // }
    {
        auto p4 = new ListNode(4);
        auto p2 = new ListNode(2);
        auto p8 = new ListNode(8);
        p4->next = p2;
        p2->next = p8;

        head = p4;
    }

    TreeNode* root = nullptr;
    // [1,
    // 4,4,
    // null,2,2,null
    // 1,null,6,8,null,null,null,null
    // 1,3]
    // {
    //     auto l = new TreeNode(9);
    //     auto p = new TreeNode(10);
    //     p->left = l;

    //     l = p;
    //     auto r = new TreeNode(1);
    //     p = new TreeNode(1);
    //     p->left = l;
    //     p->right = r;

    //     r = p;
    //     p = new TreeNode(1);
    //     p->right = r;

    //     root = p;
    // }
    {
        auto l = new TreeNode(1);
        auto r = new TreeNode(3);
        auto p = new TreeNode(8);
        p->left = l;
        p->right = r;

        r = p;
        l = new TreeNode(6);
        p = new TreeNode(2);
        p->left = l;
        p->right = r;

        l = p;
        p = new TreeNode(4);
        p->left = l;

        r = p;
        p = new TreeNode(1);
        p->right = r;

        auto p1 = new TreeNode(1);
        auto p2 = new TreeNode(2);
        auto p4 = new TreeNode(4);
        p2->left = p1;
        p4->right = p2;
        p->left = p4;

        root = p;
    }
    // lc::ParseArg(in[0], head);
    // lc::ParseArg(in[1], root);
    // DUMP(ARGS);

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
    // std::cin >> t;
    while (t--) Solve();

    return 0;
}
