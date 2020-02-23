#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// 1 总边数 = 顶点数-1 (树2)
// 2 每个节点最多被另外1个节点所指向, 其中有一个节点不能被指向(树1)
// 3 每个节点最多只能指向2个其他节点(二叉树)
// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
const int N = 1e4 + 9;
vector<int> pt[N];  // 指向别人
vector<int> be[N];  // 被别人指向
class Solution {
    void init(int n) {
        for (int i = 0; i < N; ++i) pt[i].clear();
        for (int i = 0; i < N; ++i) be[i].clear();
    }
    bool validate1(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int sum = 0;
        for (int i = 0; i < leftChild.size(); ++i) {
            int a = i;
            int b = leftChild[i];
            if (b != -1) {
                sum += 1;
                pt[a].push_back(b);  // 指向b
                be[b].push_back(a);  // 被a指向
            }
        }
        for (int i = 0; i < rightChild.size(); ++i) {
            int a = i;
            int b = rightChild[i];
            if (b != -1) {
                sum += 1;
                pt[a].push_back(b);
                be[b].push_back(a);
            }
        }

        if (sum == n - 1)
            return true;
        return false;
    }
    bool validate2(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int flag = 0;  // 没有被指向的节点数
        for (int i = 0; i < n; ++i) {
            if (be[i].size() == 0) {
                flag += 1;
                if (flag > 1)
                    return false;
            } else if (be[i].size() != 1) {
                return false;
            }
        }

        return true;
    }
    bool validate3(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for (int i = 0; i < n; ++i) {
            if (pt[i].size() > 2) {
                return false;
            }
        }
        return true;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        init(n);
        if (!validate1(n, leftChild, rightChild)) {
            DUMP("1111");
            return false;
        }
        
        if (!validate2(n, leftChild, rightChild)) {
            DUMP("2222");
            return false;
        }
        
        if (!validate3(n, leftChild, rightChild)) {
            DUMP("333");
            return false;
        }
        
        return true;
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

    #define FUNC validateBinaryTreeNodes
    #define ARGS arg0, arg1, arg2
    int arg0;
    vector<int> arg1;
    vector<int> arg2;
    // int arg3;
    lc::ParseArg(in[0], arg0);
    lc::ParseArg(in[1], arg1);
    lc::ParseArg(in[2], arg2);
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
