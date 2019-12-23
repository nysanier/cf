#include <iostream>
#include <algorithm>
#include <set>

int main() {
    std::string str;
    while (std::cin >> str) {
        std::set<char> cur;
        for (auto ch : str) {
            if (cur.find(ch) != cur.end()) {
                continue;
            }

            cur.insert(ch);
            std::cout << ch;
        }
        std::cout << std::endl;
        
    }

    return 0;
}
