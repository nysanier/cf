// 数独1-9
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include <assert.h>
#include <stdio.h>

const int N = 9;
int a[N][N];
std::vector<std::pair<int, int>> pos;
bool flag = true;

template <typename C>
void DumpAvail(int i, int j, const C& c) {
    // 只打印在check中的值
    // std::set<std::pair<int, int>> check{
    //     {4, 0},
    // };
    // if (check.find({i,j}) == check.end()) {
    //     return;
    // }

    // printf("avail[%d][%d]: ", i, j);
    // for (auto v : c) {
    //     std::cerr << v << " ";
    // }
    // std::cerr << std::endl;
}

template <typename C>
void Dump2(const C& c) {
    // std::cerr << "dump: ";
    // for (auto& kv : c) {
    //     std::cerr << "<" << kv.first << "," << kv.second << "> ";
    // }
    // std::cerr << std::endl;
}

void Try(int i, int j, int v) {
    // 只打印在check中的值
    // std::set<std::pair<int, int>> check{
    //     {4, 0},
    // };
    // if (check.find({i,j}) == check.end()) {
    //     return;
    // }

    // printf("try[%d][%d]: %d\n", i, j, v);
}

void Ans() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Mid() {
    // static int test = 0;
    // std::cerr << test << "] ----- " << std::endl;
    // ++test;
    // Ans();
}

// a[i][j]这个位置可以选择的数
void Avail(int i, int j, std::set<int>& avail) {
    std::set<int> cur;
    for (int x = 0; x < N; ++x) {
        auto r = a[i][x];
        auto c = a[x][j];
        if (r > 0) {
            cur.insert(r);
        }
        if (c > 0) {
            cur.insert(c);
        }
    }

    avail.clear();
    for (int i = 1; i <= N; ++i) {
        if (cur.find(i) == cur.end()) {
            avail.insert(i);
        }
    }
}

void Dfs(size_t d) {
    if (d >= pos.size()) {
        return;
    }

    auto i = pos[d].first;
    auto j = pos[d].second;
    std::set<int> avail;
    Avail(i, j, avail);
    DumpAvail(i, j, avail);
    // 只要存在一个0无法取值，那么本次search就失败了
    if (avail.empty()) {
        Mid();
        return;
    }

    // final
    if (d == pos.size() - 1) {
        // printf("flag[%d][%d]\n", i, j);
        flag = true;
        a[i][j] = *avail.begin();
        Ans();
        return;
    }

    // try
    for (auto v : avail) {
    // for (auto it = avail.rbegin(); it != avail.rend(); ++it) {
    //     auto v = *it;
        if (flag) {
            return;
        }
        Try(i, j, v);
        // printf("[%d][%d] d=%d trying %d\n", i, j, (int)d, v);
        a[i][j] = v;
        Dfs(d + 1);
        a[i][j] = 0;
    }
}

int main() {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> a[i][j];
            if (a[i][j] == 0) {
                cnt += 1;
                pos.push_back({i, j});
            }
        }
    }

    Dump2(pos);
    if (pos.size() > 0) {
        flag = false;
        Dfs(0);
    }
    if (!flag) {
        std::cerr << "no solution" << std::endl;
        assert(0);
        return 0;
    }

    return 0;
}

/*
N 1
1

N 2
0 0
0 1

N 2
1 0
0 2

N 3
0 2 0
2 0 0
0 0 2

N 9
7 2 6 9 3 4 8 5 1
5 8 9 6 1 7 4 3 2
3 4 1 2 8 5 7 6 9
1 5 2 4 6 8 3 9 7
4 3 7 1 9 2 6 8 5
6 9 8 5 7 3 2 1 4
2 1 5 8 4 6 9 7 3
9 6 3 7 2 1 5 4 8
8 7 4 3 5 9 1 2 6

N 9
7 2 6 9 0 4 0 5 1
0 8 0 6 0 7 4 3 2
3 4 1 0 8 5 0 0 9
0 5 2 4 6 8 0 0 7
0 3 7 0 0 0 6 8 0
0 9 0 0 0 3 0 1 0
0 0 0 0 0 0 0 0 0
9 0 0 0 2 1 5 0 0
8 0 0 3 0 0 0 0 0

*/
