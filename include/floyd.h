#pragma once

#include <bits/stdc++.h>

namespace fn {

// floyd 算法，计算任意两点间的最短距离
//   如果两点不可达，认为是INF距离
//   算法复杂度O(n^3)
const int INF = 1e8;
// 可以直接引用外面的二维数组!
// const int N = 100 + 9;
// int mat[N][N];
void floyd(std::vector<std::vector<int>>& mat, const std::vector<std::vector<int>>& edges) {
    // 初始化1: 全部设置为INF
    int n = mat.size();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][j] = INF;

    // 初始化2: 连通的两点设置为边长权重
    for (auto& v : edges) {
        int a = v[0];
        int b = v[1];
        int w = v[2];
        mat[a][b] = mat[b][a] = w;
    }

    // 计算最短距离
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (i != j && mat[i][k]+mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
}

}
