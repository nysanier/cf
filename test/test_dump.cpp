#include <dump.h>

int main() {
    int32_t a = 1;
    int64_t b = 2;
    double c = 3;
    std::string d = "4,5";
    char e = '6';

    std::vector<long> f{1,3,4,2};
    std::set<long> g{1,3,4,1};
    std::pair<std::string, long> h{"abc", 123};
    std::map<long, std::string> i{{1,"a"},{3,"c"},{2,"b"},{1,"d"}};
    std::vector<std::vector<long>> j{{1,2,3},{9,8,7}};

    DUMP();
    DUMP(a);
    DUMP(a, b);
    DUMP(a, b, c);
    DUMP(a,b,c,d);
    DUMP(a,b,c,d,e);
    DUMP(a,b,c,d,e,f);
    DUMP(a,b,c,d,e,f,g);
    DUMP(a,b,c,d,e,f,g,h);
    DUMP(a,b,c,d,e,f,g,h,i);
    DUMP(a,b,c,d,e,f,g,h,i,j);

    return 0;
}
