#pragma once

struct UnionFind {
    static const int N = 26;
    int parent[N];

    // all point to self
    void Init() {
        for (int i = 0; i < N; ++i) {
            parent[i] = i;
        }
    }

    // find the root of x
    int Find(int x) {
        int r = x;
        while (parent[r] != r) {
            r = parent[r];
        }

        // zip all the element begin x and root
        int i = x;
        while (i != r) {
            int tmp = parent[i];
            parent[i] = r;  // point to root
            i = tmp;
        }
        return r;
    }

    void Merge(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);
        if (fx != fy) {
            parent[fx] = fy;  // root1 point root2, so all point to root2
        }
    }
};
