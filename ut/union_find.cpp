#include <assert.h>
#include <stdio.h>
#include <set>
#include "union_find.h"

int main() {
    UnionFind uf;
    uf.Init();
    for (int i = 0; i < 26; ++i) {
        assert(uf.parent[i] == i);
    }

    for (int i = 1; i < 26; ++i) {
        uf.Merge(i - 1, i);
    }

    std::set<int> setx;
    for (int i = 0; i < 26; ++i) {
        auto pa = uf.Find(i);
        setx.insert(pa);
        // printf("%d] find(%d) %d\n", i, pa, uf.parent[i]);
    }
    assert(setx.size() == 1u);  // 最终大家都是指向同一个root

    return 0;
}
