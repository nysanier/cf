#pragma once

#include <bits/stdc++.h>

namespace fn {

// combination 组合函数生成器
// n 个里面选 m 个
// 返回值不用管
int comb(int n, int m, std::vector<int> one,
         std::set<std::set<int>>& all) {
    if (m == 0) return 1;
    int x = n;
    while (x >= m) {
        one.push_back(x);
        if (comb(x-1, m-1, one, all))
            all.insert({one.begin(), one.end()});
        one.pop_back();
        x -= 1;
    }
    return 0;
}

// n个里面选a-b个的所有情况
// 这里选择的是1-n,而不是从0开始
void comball(int n, int a, int b, std::set<std::set<int>>& all) {
    assert(a <= b);
    assert(a >= 1);
    assert(b <= n);
    all.clear();
    std::vector<int> one;
    for (int i = a; i <= b; ++i) {
        comb(n, i, one, all);
    }
}



// 得到的结果是反向的,比如5,4,3,2,1
//   或者: 5|4, 4|3 这样, 看着不舒服
int comb_bk(int n, int m, std::vector<int> one,
         std::vector<std::vector<int>>& all) {
    if (m == 0) return 1;
    int x = n;
    while (x >= m) {
        one.push_back(x);
        if (comb_bk(x-1, m-1, one, all))
            all.push_back(one);
        one.pop_back();
        x -= 1;
    }
    return 0;
}

// 反着来
void comball_bk(int n, int a, int b, std::vector<std::vector<int>>& all) {
    assert(a <= b);
    assert(a >= 1);
    assert(b <= n);
    all.clear();
    std::vector<int> one;
    for (int i = a; i <= b; ++i) {
        comb_bk(n, i, one, all);
    }
}

}
