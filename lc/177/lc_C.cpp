#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// 1 分解质因素
// 2 bruteforce 找到最接近的两个因素
// 3 x 和 y 比较
// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    void f1(int n, map<int, int>& mp) {
        mp.clear();
        while (n > 1) {
            bool flag = false;  // 是否找到质因数, 如果找不到, 那么本身就已经是质数了
            for (int i = 2; i * i <= n; ++i) {
                if (n % i == 0) {
                    DUMP(n, i);
                    mp[i] += 1;
                    n /= i;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                mp[n] += 1;
                n = 1;
            }
            // DUMP("next", n);
        }
    }

    int cm(int n, int m, vector<int> out, vector<vector<int>>& total) {
        if (m==0)
            return 1;
        int x = n;
        while (x >= m) {
            out.push_back(x);
            if (cm(x-1, m-1, out, total)) {
                // DUMP(out);
                total.push_back(out);
            }
            out.pop_back();
            x -= 1;
        }
        return 0;
    }

    // 组合
    void fc(map<int, int>& mp, int& a, int& b) {
        vector<int> vec;
        int total = 1;
        for (auto& kv : mp)
            if (kv.second > 0) {
                for (int i = 0; i < kv.second; ++i)
                    vec.push_back(kv.first);
                total *= kv.first * kv.second;
            }
        DUMP(vec);
        if (vec.empty()) {
            a = b = 1;
            return;
        } else if (vec.size() == 1) {
            a = 1;
            b = vec[0];
            return;
        } else if (vec.size() == 2) {
            a = vec[0];
            b = vec[1];
            return;
        }

        // 暴力求解
        int d = 1e8;
        vector<vector<int>> vvec;
        for (int i = 1; i < (vec.size()+2) / 2; ++i) {
            vector<int> out;
            cm(vec.size(), i, out, vvec);
        }
        DUMP(vvec);
        for (auto v1 : vvec) {
            int a1 = 1;
            for (auto v2 : v1)
                a1 *= vec[v2-1];
            int b1 = total / a1;
            int d1 = abs(a1 - b1);
            // DUMP(d1, a1, b1);
            if (d1 < d) {
                d = d1;
                a = a1;
                b = b1;
                // DUMP(d, a, b);
            }
        }
    }

    void f2(map<int, int>& mp, int& d, vector<int>& r) {
        int c = 1;  // 公约数
        // for (auto& kv : mp) {
        //     if (kv.second > 1) {
        //         int x = kv.second / 2;
        //         c *= kv.first * x;
        //         kv.second -= x * 2;
        //     }
        // }
        DUMP(c);

        int a, b;
        fc(mp, a, b);
        a *= c;
        b *= c;
        r.push_back(a);
        r.push_back(b);
        d = abs(a-b);
    }

public:
    vector<int> closestDivisors(int num) {
        // vector<int> cmout;
        // auto cmr = cm(5, 3, cmout);
        // DUMP(5, 3, cmout, cmr);


        map<int, int> mp1, mp2;
        int n1 = num + 1;
        int n2 = num + 2;
        f1(n1, mp1);
        f1(n2, mp2);
        DUMP(n1, mp1);
        DUMP(n2, mp2);

        int d1, d2;
        vector<int> r1, r2;
        vector<int> r;
        f2(mp1, d1, r1);
        f2(mp2, d2, r2);
        // DUMP(d1, r1);
        // DUMP(d2, r2);
        if (d1 < d2) {
            r.swap(r1);
        } else {
            r.swap(r2);
        }
    
        return r;
    }
};

}

void Init() {}
void Solve() {
    using namespace std;

    static int idx = 0;
    vector<string> in;
    std::string out;
    lc::Read(in, out);
    DUMP("------", idx, in, out);
    idx +=1;

    #define FUNC closestDivisors
    #define ARGS arg0
    int arg0;
    // int arg1;
    // int arg2;
    // int arg3;
    lc::ParseArg(in[0], arg0);
    // lc::ParseArg(in[1], arg1);
    // lc::ParseArg(in[2], arg2);
    // lc::ParseArg(in[3], arg3);
    DUMP(ARGS);

    Solution sol;
    auto r = sol.FUNC(ARGS);
    DUMP(out, r);
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
    std::cin >> t;
    while (t--) Solve();

    return 0;
}
