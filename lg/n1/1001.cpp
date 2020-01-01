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
    auto c = a + b;
    // co("");  // 不能有前置空格
    co(c);  // 可以有后置多余的空格
    col("");
    col("");  // 可以有多余回车

    return 0;
}
