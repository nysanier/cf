#include "pbds_tree.h"
#include "macro.h"

int main() {
    PbdsTree tree;
    int n = 5;
    for1r(i, n) {
        tree.insert(i);
    }

    for (auto v : tree) {
        printf("%d\n", v);
    }

    for0(i, n) {
        // 二分的方式在找这个数, 类似线段树的方式, 因此对于要找前找后的找k这个数来说find都是O(logn)的效率
        auto it = tree.find_by_order(i);  // 找第i个数(从0递增)
        printf("%d]: find: %d\n", i, *it);
    }


    return 0;
}
