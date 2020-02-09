#include <bits/stdc++.h>
// #include <bits/extc++.h>
#include "lc.h"

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class TweetCounts {
    using Map = std::map<string, std::map<int, int>>;
    Map ss;
public:
    TweetCounts() {
    }

    void recordTweet(string tweetName, int time) {
        auto& s = ss[tweetName];
        s[time] += 1;
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int d;
        if (freq == "minute") {
            d = 60;
        } else if (freq == "hour") {
            d = 3600;
        } else {
            d = 3600 * 24;
        }

        auto& s = ss[tweetName];
        DUMP(s, startTime, endTime);
        vector<int> r;
        int t1 = startTime;
        int t2 = std::min(t1 + d - 1, endTime);
        DUMP(t1, t2);
        auto it1 = s.lower_bound(t1);
        auto it2 = s.upper_bound(t2);
        int idx = 0;
        while (t1 <= endTime) {
            int cnt = 0;
            for (auto it = it1; it != it2; ++it) {
                cnt += it->second;
                DUMP(idx, it->first);
            }
            idx += 1;
            r.push_back(cnt);

            t1 = t2 + 1;
            t2 = std::min(t1 + d - 1, endTime);
            DUMP(t1, t2);
            it1 = s.lower_bound(t1);
            it2 = s.upper_bound(t2);
        }

        return r;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */

}
/*
["TweetCounts","recordTweet","recordTweet","recordTweet","recordTweet",
"recordTweet","getTweetCountsPerFrequency","recordTweet","recordTweet",
"recordTweet","recordTweet","recordTweet","recordTweet","recordTweet"]

[[],["tweet0",99],["tweet1",80],["tweet2",29],["tweet3",81],
["tweet4",56],["day","tweet4",56,2667],["tweet1",56],["tweet0",96],["tweet4",35],
["tweet1",51],["tweet2",45],["tweet0",74],["tweet1",63]]


["TweetCounts","recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency",
"getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"]
[[],["tweet3",0],["tweet3",60],["tweet3",10],["minute","tweet3",0,59],
["minute","tweet3",0,60],["tweet3",120],["hour","tweet3",0,210]]
*/
void Init() {}
void Solve() {
    using namespace std;

//     std::vector<std::string> v1 = {"recordTweet","recordTweet","recordTweet","getTweetCountsPerFrequency",
// "getTweetCountsPerFrequency","recordTweet","getTweetCountsPerFrequency"};
//     std::vector<std::pair<std::string,int>> v2 = {{"tweet3",0},{"tweet3",60},{"tweet3",10},{"minute","tweet3",0,59},
// {"minute","tweet3",0,60},{"tweet3",120},{"hour","tweet3",0,210}};

    TweetCounts sol;
    vector<int> r;
    sol.recordTweet("tweet3",0);
    sol.recordTweet("tweet3",60);
    sol.recordTweet("tweet3",10);
    r = sol.getTweetCountsPerFrequency("minute","tweet3",0,59); DUMP(r);
    r = sol.getTweetCountsPerFrequency("minute","tweet3",0,60); DUMP(r);
    sol.recordTweet("tweet3",120);
    r = sol.getTweetCountsPerFrequency("hour","tweet3",0,210); DUMP(r);

    /*
    ["tweet0",99],["tweet1",80],["tweet2",29],["tweet3",81],["tweet4",56],
    ["day","tweet4",56,2667],
    ["tweet1",56],["tweet0",96],["tweet4",35],["tweet1",51],["tweet2",45],["tweet0",74],["tweet1",63]]
    */
    // sol.recordTweet("tweet0",99);
    // sol.recordTweet("tweet1",80);
    // sol.recordTweet("tweet2",29);
    // sol.recordTweet("tweet3",81);
    // sol.recordTweet("tweet4",56);
    // r = sol.getTweetCountsPerFrequency("day","tweet4",56,2667); DUMP(r);
    // sol.recordTweet("tweet1",56);
    // sol.recordTweet();
    // sol.recordTweet();
    // sol.recordTweet();
    // sol.recordTweet();
    // sol.recordTweet();
    // sol.recordTweet();

    

    // auto r = sol.func(arg0, arg1, arg2, arg3);
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
