#include "abbr.h"

int main() {
    std::vector<int> a{0,1,2,3,4,5,6,7,8,9};

    // output
    for0(i, 5) co(a[i]); col("for0");
    for1(i, 5) co(a[i]); col("for1");
    forn(i, 2, 5) co(a[i]); col("forn");
    for0r(i, 5) co(a[i]); col("for0r");
    for1r(i, 5) co(a[i]); col("for1r");
    fornr(i, 2, 5) co(a[i]); col("fornr");

    forxy(i, 3, 7) co(a[i]); col("forxy");
    foryx(i, 3, 7) co(a[i]); col("foryx");
    forxyd(i, 3, 7, 2) co(a[i]); col("forxyd");
    foryxd(i, 3, 7, 2) co(a[i]); col("foryxd");

    // Vec ans(a, a+n);
    // col(ans.size());
    // for (auto v : ans) co(v);
    // col("");
    return 0;
}
