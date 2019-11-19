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

char s[212345];

char NextChar(char ch) {
    if (ch == 'z') {
        return 'a';
    } else {
        return ch + 1;
    }
}

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            s[i] = NextChar(s[i]);

            if (i + 1 < n && s[i] == s[i+1]) {
                s[i] = NextChar(s[i]);
            }
        }
    }

    printf("%s\n", s);

    return 0;
}
