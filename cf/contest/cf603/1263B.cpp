#include "bits/stdc++.h"

int t;
char cards[10][5];

void Case() {
    std::set<char> setx;
    std::map<std::string, int> mapx;
    std::set<std::string> res;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cards[i]);
        mapx[cards[i]] += 1;
        // for (int x = 0; x < 4; ++x) {
        //     setx[x].insert(cards[i][x]);
        // }
        setx.insert(cards[i][0]);
    }

    int sum = 0;
    for (auto it = mapx.begin(); it != mapx.end(); ++it) {
        res.insert(it->first);
        int len = it->second;
        if (len == 1) {
            continue;
        }

        sum += len - 1;
        for (int i = 1; i < len; ++i) {
            std::string str = it->first;
            char ch = '0';
            for (; ch <= '9'; ch += 1) {
                if (setx.count(ch) == 0) {
                    break;
                }
            }
            str[0] = ch;
            setx.insert(ch);
            res.insert(str);
        }
    }

    // printf("res.size = %d\n", (int)res.size());
    assert(res.size() == n);
    printf("%d\n", sum);
    for (auto& str : res) {
        printf("%s\n", str.c_str());
    }
}

void Case2() {
    std::set<char> setx;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cards[i]);
        setx.insert(cards[i][0]);
    }

    int sum = 0;
    for (int a = 0; a < n; ++a) {
        int equal = 0;
        for (int b = 0; b < n; ++b) {
            if (std::string(cards[a]) == std::string(cards[b])) {
                equal += 1;
            }
        }
        assert(equal >= 1);
        if (equal == 1) {
            continue;
        }

        sum += 1;
        char ch = '0';
        for (; ch <= '9'; ch += 1) {
            if (setx.count(ch) == 0) {
                break;
            }
        }
        cards[a][0] = ch;
        setx.insert(ch);
    }

    printf("%d\n", sum);
    for (int i = 0; i < n; ++i) {
        printf("%s\n", cards[i]);
    }
}

int main() {
    // printf(">\n");
    scanf("%d", &t);
    while (t--) {
        Case2();
    }
    

    // std::cout << N << std::endl;
    return 0;
}
