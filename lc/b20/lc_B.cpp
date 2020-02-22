#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Cashier {
    int n_;
    int discount_;
    // vector<int> products_;
    // vector<int> prices_;
    int idx = 1;
    map<int, int> mp;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        n_ = n;
        discount_ = discount;
        // products_.swap(products);
        // prices_.swap(prices);
        assert(products.size() == prices.size());
        for (int i = 0; i < products.size(); ++i) {
            mp[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        int dis = 0;
        if (idx % n_ == 0) dis = discount_;
        idx += 1;
        double sum = 0;
        assert(product.size() == amount.size());
        for (int i = 0; i < product.size(); ++i) {
            sum += mp[product[i]] * amount[i];
        }
        double r = sum - (dis * sum) / 100.0;
        return r;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */

}

void Init() {}
void Solve() {
    using namespace std;

    int n = 3;
    int discount = 50;
    vector<int> products = {1,2,3,4,5,6,7};
    vector<int> prices = {100,200,300,400,300,200,100};
    auto p = new Cashier(n, discount, products, prices);

    vector<vector<vector<int>>> vvvec = {
        {{1,2},{1,2}},
        {{3,7},{10,10}},
        {{1,2,3,4,5,6,7},{1,1,1,1,1,1,1}},
        {{4},{10}},
        {{7,3},{10,10}},
        {{7,5,3,1,6,4,2},{10,10,10,9,9,9,7}},
        {{2,3,5},{5,3,2}}
    };
    for (auto& vvec : vvvec) {
        auto r = p->getBill(vvec[0], vvec[1]);
        DUMP(r);
    }


    // static int idx = 0;
    // vector<string> in;
    // std::string out;
    // lc::Read(in, out);
    // DUMP("------", idx, in, out);
    // idx +=1;

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
