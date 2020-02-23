#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include <chrono>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
// static std::chrono::system_clock::time_point from_time_t( std::time_t t ) noexcept;
    std::chrono::system_clock::time_point getTp(const string& s) {
        auto t1 = time(NULL);
        struct tm tm1 = *localtime(&t1);
        int year, mon, day;
        sscanf(s.c_str(), "%d-%d-%d", &year, &mon, &day);
        tm1.tm_year = year - 1900;
        tm1.tm_mon = mon - 1;
        tm1.tm_mday = day;
        auto t2 = mktime(&tm1);
        auto tp = std::chrono::system_clock::from_time_t(t2);
        return tp;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        auto t1 = getTp(date1);
        auto t2 = getTp(date2);
        auto d = t2 - t1;
        auto td = std::chrono::duration_cast<std::chrono::hours>(d);
        auto c = td.count();
        auto r = c / 24;
        return abs(r);
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

    #define FUNC daysBetweenDates
    #define ARGS arg0, arg1
    string arg0;
    string arg1;
    // int arg2;
    // int arg3;
    lc::ParseArg(in[0], arg0);
    lc::ParseArg(in[1], arg1);
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
