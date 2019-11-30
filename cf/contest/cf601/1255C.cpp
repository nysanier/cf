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

// const int N = 10;
const int N = 512345;
int n;
// int p[N];
int q[N][3];
std::set<int> ss[N];  // i -> q
std::set<int> head1;
std::set<int> head2;

int main() {
    // printf(">\n");
    scanf("%d", &n);
    for (int i = 0; i < n - 2; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        q[i][0] = a;
        q[i][1] = b;
        q[i][2] = c;
        ss[a].insert(i);
        ss[b].insert(i);
        ss[c].insert(i);
    }

    int val = -1;
    int idx = -1;
    for (int i = 1; i <= n; ++i) {
        if (val == -1 && ss[i].size() == 1u) {
            val = i;
            idx = *ss[i].begin();
        }

        if (ss[i].size() == 1u) {
            head1.insert(i);
        }
        if (ss[i].size() == 2u) {
            head2.insert(i);
        }
    }

    head1.erase(val);
    for (int x = 0; x < 3; ++x) {
        int v = q[idx][x];
        if (ss[v].size() == 2u) {
            head2.erase(v);
        }
    }
    std::string last = " " + std::to_string(*head2.begin());
    last += " " + std::to_string(*head1.begin());

    printf("%d", val);

    for (int i = 0; i < n - 3; ++i) {
        int val2 = -1;
        int idx2 = -1;
        for (int x = 0; x < 3; ++x) {
            int v = q[idx][x];
            ss[v].erase(idx);
            if (ss[v].size() == 1u && head1.count(v) == 0 && head2.count(v) == 0) {
                val2 = v;
                idx2 = *ss[v].begin();
            }
        }
        val = val2;
        idx = idx2;
        printf(" %d", val);
    }
    printf("%s\n", last.c_str());

    return 0;
}

/*
6
2 3 1
3 4 5
4 6 5
4 3 2

*/
