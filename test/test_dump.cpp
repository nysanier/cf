#include "dump.h"

int main() {
    // int32/int64/double/string/char
    int32_t i32 = 1;
    int64_t i64 = 2;
    double d = 3;
    std::string str = "4,5";
    char ch = '6';

    // pair/vector
    std::pair<std::string, long> pr{"abc", 123};
    std::vector<long> vec{2,3,2,1};

    // deque/list/set/multiset/unordered_set
    std::deque<long> deq(vec.begin(), vec.end());
    std::list<long> lst(vec.begin(), vec.end());
    std::set<long> st(vec.begin(), vec.end());
    std::multiset<long> mst(vec.begin(), vec.end());
    std::unordered_set<long> ust(vec.begin(), vec.end());

    // vec<pair>/map/multimap/unordered_map
    std::vector<std::pair<long, std::string>> vpr{{2,"b"},{3,"c"},{1,"a"},{2,"bb"}};
    std::map<long, std::string> mp(vpr.begin(), vpr.end());
    std::multimap<long, std::string> mmp(vpr.begin(),vpr.end());
    std::unordered_map<long, std::string> ump(vpr.begin(),vpr.end());

    // vec<vec>
    std::vector<std::vector<long>> vvec{{2},{3},{1},{2}};

    // map<vec>
    std::map<std::string, std::vector<long>> mvec{{"b",{2}},{"c",{3}},{"a",{1}},{"b",{22}}};

    LINE("int32/int64/double/string/char");
    DUMP();
    DUMP(i32);
    DUMP(i32, i64);
    DUMP(i32, i64, d);
    DUMP(i32, i64, d, str);
    DUMP(i32, i64, d, str, ch);

    LINE("pair/vector");
    DUMP(pr);
    DUMP(vec);

    LINE("deque/list/set/multiset/unordered_set");
    DUMP(deq);
    DUMP(lst);
    DUMP(st);
    DUMP(mst);
    DUMP(ust);

    LINE("vec<pair>/map/multimap/unordered_map");
    DUMP(vpr);
    DUMP(mp);
    DUMP(mmp);
    DUMP(ump);

    LINE("vec<vec>");
    DUMP(vvec);

    LINE("map<vec>");
    DUMP(mvec);

    return 0;
}
