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

    int a, b;
    std::cin >> a >> b;
    DUMP(a, b);
    auto c = 10*a + b;
    auto ans = c / 19;
    col(ans);

    return 0;
}
