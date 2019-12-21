#include "cio.h"

namespace std {
    string to_string(const vector<string>& vec) {
        std::string res = "{";
        for (const auto& v : vec) res += v + ",";
        if (res == "{") res += "}";
        else *--res.end() = '}';
        return res;
    }
}

void Split(const std::string& str, const std::string& sep, std::vector<std::string>& vec) {
    std::string::size_type p = 0;
    while (p < str.size()) {
        auto p2 = str.find(sep, p);
        if (p2 == str.npos)
            p2 = str.size();
        vec.push_back(str.substr(p, p2-p));
        p = p2 + sep.size();
    }
}

std::string Merge(const std::string& a, const std::string& b) {
    std::vector<std::string> v1, v2;
    Split(a, ",", v1);
    Split(b, ",", v2);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "v1: " << std::to_string(v1) << std::endl;
    std::cout << "v2: " << std::to_string(v2) << std::endl;
    std::string res;
    for (size_t i = 0, j = 0; i < v1.size() && j < v2.size(); ++i, ++j) {
        res += v1[i] + "=" + v2[j] + ",";
    }
    if (!res.empty())
        res.resize(res.size()-1);
    return res;
}
#define DUMP(args...) \
    do { \
        const std::string s1 = #args; \
        const std::string s2 = sol(args); \
        const auto res = Merge(s1, s2); \
        std::cout << "DUMP: {" << res << "}" << std::endl; \
     } while (0)

int main() {
    int a = 1;
    double b = 2;
    char c = '3';
    std::string d = "4";
    long e = 5;
    co(a, b, c, d, e);

    // ?
    stream_params(std::cout, a, b, c);

    DUMP();
    DUMP(a);
    DUMP(a,b);
    DUMP(a,b,c);

    return 0;
}
