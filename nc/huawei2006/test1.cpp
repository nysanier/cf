#include <iostream>
#include <list>
#include <assert.h>

int main() {
    int n;
    while (std::cin >> n) {
        if (n <= 0) {  // not valid n!
            continue;
        }

        if (n >= 1000) {
            n = 1000;
        }

        std::list<int> l;
        for (int i = 0; i < n; ++i) {
            // std::cerr << "adding: " << i << std::endl;
            l.push_back(i);
        }
        // l.push_back(3);
        // l.push_back(6);

        auto it = l.begin();
        while (l.size() > 1u) {
            for (int i = 0; i < 2; ++i) {
                // std::cerr << "----skipping: " << *it << std::endl;
                ++it;
                if (it == l.end()) {
                    it = l.begin();
                }
            }
            // std::cerr << "erasing: " << *it << std::endl;
            it = l.erase(it);
            if (it == l.end()) {
                it = l.begin();
            }
        }
        std::cout << *l.begin() << std::endl;
    }

    return 0;
}
