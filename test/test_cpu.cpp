// C
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define BENCH_TIMER

#ifdef BENCH_TIMER
# include <boost/timer/timer.hpp>
#endif

const int N = 1e4 + 9;
// NlogN, N = 1e6:
//   i5-7600: 0.063968s wall, 0.060000s user + 0.000000s system = 0.060000s CPU (93.8%)
//   oj: 93 ms	3900 KB

// NlogN, N = 1e7:
//   i5-7600: 0.751747s wall, 0.740000s user + 0.000000s system = 0.740000s CPU (98.4%)
//   oj: 701 ms	39100 KB

// N^2, N = 1e4:
//   i5-7600: 0.055466s wall, 0.050000s user + 0.000000s system = 0.050000s CPU (90.1%)
//   oj: 156 ms	0 KB

int a[N];

#ifdef BENCH_TIMER
# define AUTO_TIMER boost::timer::auto_cpu_timer auto_timer
#else
# define AUTO_TIMER
#endif

void TestN() {
    AUTO_TIMER;
    srand(0);
    for (int i = 0; i < N; ++i) {
        a[i] = rand();
    }
}

void TestLogN() {
    AUTO_TIMER;
    TestN();
    std::sort(a, a + N);
}

void TestN2() {
    AUTO_TIMER;
    TestN();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (a[i] > a[j]) {
                std::swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    // TestLogN();
    TestN2();

    return 0;
}
