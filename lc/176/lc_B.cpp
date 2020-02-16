#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// 这种一般都是数据结构题！！！
// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class ProductOfNumbers {
    // int64_t r = 1;
    map<int, int> mp;
    int idx;
    int n;
public:
    ProductOfNumbers() {
        n = 0;
        idx = 0;
        mp.clear();
    }

    void add(int num) {
        n += 1;
        if (num == 1) {
            idx += 1;
            return;
        }
        mp[idx] = num;
        idx += 1;
    }

    int getProduct(int k) {
        int h = 0;
        if (n > k) h = n - k;
        int r = 1;
        for (auto it = mp.lower_bound(h); it != mp.end(); ++it) {
            if (it->second == 0) return 0;
            r *= it->second;
        }
        return r;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

}

void Init() {}
void Solve() {
    using namespace std;

    // static int idx = 0;
    // vector<string> in;
    // std::string out;
    // lc::Read(in, out);
    // DUMP("------", idx, in, out);
    // idx +=1;

    ProductOfNumbers* obj = new ProductOfNumbers();
    for (auto num : vector<int>{3, 0, 2, 5, 4})
        obj->add(num);
    for (auto k : vector<int>{2,3,4}) {
        auto r = obj->getProduct(k);
        DUMP(k, r);
    }
    for (auto num : vector<int>{8})
        obj->add(num);
    for (auto k : vector<int>{2}) {
        auto r = obj->getProduct(k);
        DUMP(k, r);
    }
    
    // #define FUNC func
    // #define ARGS arg0, arg1, arg2, arg3
    // int arg0;
    // int arg1;
    // int arg2;
    // int arg3;
    // lc::ParseArg(in[0], arg0);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    // DUMP(ARGS);

    // Solution sol;
    // auto r = sol.FUNC(ARGS);
    // DUMP(out, r);
    // assert(out == to_string(r));
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Init();
    int t = 1;
    // std::cin >> t;
    while (t--) Solve();

    return 0;
}
