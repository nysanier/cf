#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    auto x = a * 60 + b;
    auto y = c * 60 + d;
    auto z = y - x;
    auto h = z / 60;
    auto m = z % 60;
    co(h); col(m);

    return 0;
}
