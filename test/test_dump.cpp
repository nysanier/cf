#include "dump.h"

int main() {
    auto str=format("%d%c", 1, 'x');
    dbg("str=%s,size=%d", str.c_str(), int(str.size()));

    dump(1);
    dump2(1,2);
    dump3(1,2,3);
    dump4(1,2,3,4);
    dump5(1,2,3,4,5);
    dump6(1,2,3,4,5,6);
    dump7(1,2,3,4,5,6,7);

    std::vector<int> vec1{1,3,2,4,3,2,1,1};
    std::set<int> set1{1,3,2,4,3,2,1,1};
    std::map<int,int> map1{{1,3},{2,4},{3,2},{1,1}};
    auto vec1str=ToStr(vec1);
    auto set1str=ToStr(set1);
    auto map1str=ToStr(map1);
    dump3(vec1str,set1str,map1str);

    return 0;
}
