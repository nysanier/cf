#include "pbds_tree.h"
#include "abbr.h"
#include "dump.h"

int main() {
    PbdsTree tree;
    int n = 5;
    for1r(i, n) {
        tree.insert(i);
    }

    for (auto v : tree) {
        DUMP(v);
    }

    for0(i, n) {
        // 二分的方式在找这个数, 类似线段树的方式, 因此对于要找前找后的找k这个数来说find都是O(logn)的效率
        auto it = tree.find_by_order(i);  // 找第i个数(从0递增)
        DUMP(i, *it);
    }

    return 0;
}
