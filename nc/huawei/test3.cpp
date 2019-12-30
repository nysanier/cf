// 这个16进制取值范围？简单起见，这里默认为是32bits，如果很长的一串，那么需要通过大数来处理，也很简单，写起来稍微麻烦点
#include <iostream>
#include <string>
#include <assert.h>

int main() {
    std::string str;
    while (std::cin >> str) {
        try {
            int n = std::stoi(str, 0, 16);
            std::cout << n << std::endl;
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            assert(0);
        }
    }

    return 0;
}
