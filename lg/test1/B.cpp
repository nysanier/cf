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
 
void Dump(const int a[], int sz) {
    for (int i = 0; i < sz; ++i) {
        printf("%d\n", a[i]);
    }
}

int N, Q;
char s[123];
char ques[2];

int main() {
    // printf(">> \n");
    scanf("%d %d", &N, &Q);
    for (int i = 0; i < N; ++i) {
        s[i] = 'A' + i;
    }
    s[N] = '\0';

    auto cmp = [](char a, char b) -> bool {
        printf("? %c %c\n", a, b);
        // fflush(stdout);
        // scanf("%s", ques);
        // if (ques[0] == '<') {
        //     return true;
        // }

        // return false;
        return a > b;
    };
    std::sort(s, s + N, cmp);

    printf("! %s\n", s);

    return 0;
}
