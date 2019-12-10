#pragma once

// union and find
struct UnionFind {
    static const int N = 26;
    int* p = nullptr;  // for local var

    // all point to self
    UnionFind() {
        p = new int[N];  // root
        for (int i = 0; i < N; ++i) {
            p[i] = i;  // first point to self
        }
    }

    // find the root of x
    int Find(int x) {
        int r = x;
        while (p[r] != r) {
            r = p[r];
        }

        // zip all the element begin x and root
        int i = x;
        while (i != r) {
            int tmp = p[i];
            p[i] = r;  // point to root
            i = tmp;
        }
        return r;
    }

    void Merge(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (rx != ry) {
            p[rx] = ry;  // root1 point root2, so all point to root2
        }
    }
};
