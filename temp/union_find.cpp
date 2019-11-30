
struct UnionFind {
    static const int N = 26;
    int parent[N];

    // 一开始都指向自己
    void Init() {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }
    }

    int Find(int x) {
        // 查找根节点
        int r = x;
        while (parent[r] != r) {
            r = parent[r];
        }

        // 优化: 路径压缩
        int i = x;
        while (i != r) {
            int tmp = parent[i];
            parent[i] = r;  // 把上级改为根节点
            i = tmp;
        }
        return r;
    }

    void Merge(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);
        if (fx != fy) {
            parent[fx] = fy;  // 两个root连接起来即可
        }
    }
};

// unit test
#include <assert.h>
#include <stdio.h>
#include <set>

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
