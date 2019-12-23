#include <iostream>
#include <assert.h>

void Solve(int n) {
    assert(n > 0);
    int ans = 0;
    for (;;) {
        assert(n > 0);
        if (n == 1) {
            std::cout << ans << std::endl;
            return;
        }

        if (n == 2) {
            ans += 1;
            std::cout << ans << std::endl;
            return;
        }

        auto d = n / 3;
        ans += d;
        n = n - 3 * d + d;
    }
}

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        Solve(n);
    }

    return 0;
}
