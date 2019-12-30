#include <iostream>
#include <algorithm>

const int N = 1000;
int a[N];
int n;

int main() {
    while (std::cin >> n) {
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        std::sort(a, a + n);
        auto p = std::unique(a, a + n);
        int n2 = p - a;
        for (int i = 0; i < n2; ++i) {
            std::cout << a[i] << std::endl;
        }
    }

    return 0;
}
