#include "bits/stdc++.h"

using ll = long long;
const int N = 1e6 + 9;

void Dump(const std::vector<int>& vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", vec[i]);
    }
}

template <typename C>
void Dump(const C& c) {
    for (auto v : c) {
        // printf("[%d] %d\n", i, vec[i]);
        printf("%d\n", v);
    }
}

int n;
char a[N];
char str[N];
int pos[N];
int k = 0;
int idx = 0;

bool CheckBrackets(int k, int& res) {
    std::stack<char> stk;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        if (str[i] == '(') {
            stk.push(str[i]);
            sum = 0;
            continue;
        }
        if (str[i] == ')') {
            if (stk.empty()) {
                return false;
            }

            stk.pop();
            sum += 1;
            res = std::max(res, sum);
        }
    }

    if (stk.empty()) {
        return true;
    }

    return false;
}

void Check() {
    int res;
    auto r = CheckBrackets(k, res);
    if (!r) {
        printf("-1 ");
    } else {
        printf("%d ", res);
    }
}

int main() {
    // printf(">\n");
    scanf("%d", &n);
    scanf("%s", a);
    for (int i = 0; i < n; ++i) {
        switch (a[i]) {
            case 'L':
                if (idx > 0) {
                    idx -= 1;
                }
                Check();
                break;
            case 'R':
                idx += 1;
                Check();
                break;
            case '(';
            
        }
    }
    printf("\n");

    // for (;;) {
    //     scanf("%s", str);
    //     int k = strlen(str);
    //     int res = 0;
    //     auto r = CheckBrackets(k, res);
    //     if (!r) {
    //         printf("check failed\n");
    //     } else {
    //         printf("ok: %d\n", res);
    //     }
    // }

    // std::cout << N << std::endl;
    return 0;
}
