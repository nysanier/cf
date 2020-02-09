#include "floyd.h"
#include "dump.h"

// 5个vertex，以下是edge情况
// 0-1: 100
// 1-2: 200
// 3-4: 400
int main() {
    std::vector<std::vector<int>> mat(5, std::vector<int>(5));
    std::vector<std::vector<int>> edges;
    edges.push_back({0,1,100});
    edges.push_back({1,2,200});
    edges.push_back({3,4,400});

    fn::floyd(mat, edges);
    int n = mat.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            DUMP(i, j, mat[i][j]);
        }
    }

    return 0;
}
