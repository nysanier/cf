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

#define XX 'X'

void Case() {
    int n;
    scanf("%d", &n);
    int a_R_beat_S;
    int b_P_beat_R;  // b(Paper beats Rock)
    int c_S_beat_P;  // c(Scissors beats Paper)
    scanf("%d %d %d", &a_R_beat_S, &b_P_beat_R, &c_S_beat_P);
    std::string strBob(n, XX);
    scanf("%s", &strBob[0]);

    int R = 0;
    int P = 0;
    int S = 0;
    for (auto ch : strBob) {
        if (ch == 'R') {
            R += 1;
        } else if (ch == 'P') {
            P += 1;
        } else if (ch == 'S') {
            S += 1;
        } else {
            assert(0);
        }
    }
    assert(R + P + S == n);

    std::string strAlice(n, XX);
    int beat_count = 0;
    for (int i = 0; i < (int)strBob.size(); ++i) {
        if (strBob[i] == 'S' && a_R_beat_S > 0) {
            strAlice[i] = 'R';
            a_R_beat_S -= 1;
            beat_count += 1;
        } else if (strBob[i] == 'R' && b_P_beat_R > 0) {
            strAlice[i] = 'P';
            b_P_beat_R -= 1;
            beat_count += 1;
        } else if (strBob[i] == 'P' && c_S_beat_P > 0) {
            strAlice[i] = 'S';
            c_S_beat_P -= 1;
            beat_count += 1;
        }
    }

    if (n % 2 == 1) {
        n += 1;
    }
    if (beat_count < n / 2) {
        printf("NO\n");
        return;
    }

    std::string rem_str;
    rem_str += std::string(a_R_beat_S, 'R');
    rem_str += std::string(b_P_beat_R, 'P');
    rem_str += std::string(c_S_beat_P, 'S');
    for (int i = 0; i < (int)strAlice.size(); ++i) {
        if (strAlice[i] == XX) {
            strAlice[i] = *rem_str.rbegin();
            rem_str.resize(rem_str.size() - 1);
        }
    }

    printf("YES\n");
    printf("%s\n", strAlice.c_str());
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        Case();
    }

    return 0;
}
