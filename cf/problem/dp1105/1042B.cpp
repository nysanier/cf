#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <limits>
#include <iostream>
#include <map>

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

int c[1001];
char s[1001][4];
std::set<char> ss[1001];
int f[7][1001] = {{0,},};

const std::set<char> A = {'A'};
const std::set<char> B = {'B'};
const std::set<char> C = {'C'};
const std::set<char> AB = {'A', 'B'};
const std::set<char> AC = {'A', 'C'};
const std::set<char> BC = {'B', 'C'};
const std::set<char> ABC = {'A', 'B', 'C'};

std::map<std::set<char>, int> set_to_idx = {
    {A, 0},
    {B, 1},
    {C, 2},
    {AB, 3},
    {AC, 4},
    {BC, 5},
    {ABC, 6},
};

std::map<int, std::set<char>> idx_to_set = {
    {0, A},
    {1, B},
    {2, C},
    {3, AB},
    {4, AC},
    {5, BC},
    {6, ABC},
};

std::string SetToStr(const std::set<char>& ss) {
    std::string ret;
    for (auto& ch : ss) {
        ret += ch;
    }
    return ret;
}

void TestIncludes() {
    // auto r = std::includes(ABC.begin(), ABC.end(), AB.begin(), AB.end());  // true
    auto r = std::includes(AC.begin(), ABC.end(), AB.begin(), AB.end());  // false
    printf("includes? %s\n", r ? "true" : "false");
}

void TestDifference() {
    std::set<char> d1;
    // std::set_difference(ABC.begin(), ABC.end(), AB.begin(), AB.end(), std::inserter(d1, d1.begin()));  // C
    std::set_difference(BC.begin(), BC.end(), AB.begin(), AB.end(), std::inserter(d1, d1.begin()));  // C
    printf("diff? %s\n", SetToStr(d1).c_str());
}

int Cost(std::set<char> t, int k) {
    if (t.empty()) {
        return 0;
    }

    // cache to f
    auto& fc = f[set_to_idx[t]][k];
    if (fc != 0) {
        return fc;
    }

    if (k == 0) {
        if (std::includes(ss[k].begin(), ss[k].end(), t.begin(), t.end())) {
            fc = c[k];
        } else {
            fc = -1;
        }
        return fc;
    }

    std::set<char> t1;
    std::set_difference(t.begin(), t.end(), ss[k].begin(), ss[k].end(), std::inserter(t1, t1.begin()));
    auto r1 = Cost(t1, k - 1);
    if (r1 >= 0) {
        r1 += c[k];
    }

    auto r2 = Cost(t, k - 1);

    if (r1 == -1 && r2 == -1) {
        fc = -1;
    } else if (r1 == -1) {
        fc = r2;
    } else if (r2 == -1) {
        fc = r1;
    } else {
        fc = std::min(r1, r2);
    }
    return fc;
}

int main() {
    // for (auto kv: set_to_idx) {
    //     printf("%s: %d\n", SetToStr(kv.first).c_str(), kv.second);
    // }
    // for (auto kv: idx_to_set) {
    //     printf("%d: %s\n", kv.first, SetToStr(kv.second).c_str());
    // }

    // TestIncludes();
    // TestDifference();

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %s", &c[i], s[i]);
        for (const char* p = s[i]; *p != '\0'; ++p) {
            ss[i].insert(*p);
        }
    }

    int ret = Cost(ABC, n - 1);
    printf("%d\n", ret);

    return 0;
}
