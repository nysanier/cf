#include <cio.h>

int main() {
    int a = 1;
    double b = 2;
    char c = '3';
    std::string d = "4";
    long e = 5;
    co(a, b, c, d, e);

    // ?
    stream_params(std::cout, a, b, c);

    return 0;
}
