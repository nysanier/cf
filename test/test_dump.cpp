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

    return 0;
}
