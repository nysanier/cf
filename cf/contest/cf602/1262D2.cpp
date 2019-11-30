#include "bits/stdc++.h"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using PbdsTree = __gnu_pbds::tree<
        int,
        __gnu_pbds::null_type,
        std::less<int>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

const int N = 2e5 + 9;  // 看到这种规模, 就要想到复杂度O(nlogn)

int n;
int a[N];
std::pair<int, int> b[N];
int m;
std::vector<std::pair<std::pair<int, int>, int>> req;  // k,pos,idx

int main() {
    // printf(">\n");
    scanf("%d", &n);
    for0(i, n) {
        scanf("%d", a + i);
        b[i] = {-a[i], i};  // for value non-incr and idx ascend
    }

    std::sort(b, b + n);
    // DumpA();

    scanf("%d", &m);
    for0(i, m) {
        int k, pos;
        scanf("%d %d", &k, &pos);
        req.push_back({{k, pos}, i});
    }

    std::sort(req.begin(), req.end());  // by k && pos
    std::vector<int> ans(m);  // ans
    PbdsTree tree;
    int x = 0;
    for (auto& kv : req) {
        int k = kv.first.first;
        int pos = kv.first.second;
        int req_idx = kv.second;
        for (; x < k; ++x) {
            int idx = b[x].second;
            tree.insert(idx);
        }
        auto it = tree.find_by_order(pos - 1);  // must can find, because, pos <= k and k is insert to tree
        ans[req_idx] = a[*it];
    }

    for (auto v : ans) {
        printf("%d\n", v);
    }

    return 0;
}
