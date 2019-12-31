#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (decltype(n) i = x; i < (n)+(x); ++i)
#define fornr(i, x, n) for (auto i = (n)-1+(x); i >= x; --i)
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (auto i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (auto i = y; i >= x; i -= d)
#define forxy(i, x, y) forxyd(i, x, y, 1)
#define foryx(i, x, y) foryxd(i, x, y, 1)
#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

// type
// using ll = int32_t;
using ll = int64_t;
using Vec = std::vector<ll>;
using Deq = std::deque<ll>;
using Lst = std::list<ll>;
using Pr = std::pair<ll, ll>;
using St = std::set<ll>;
using Mst = std::multiset<ll>;
using Ust = std::unordered_set<ll>;
using Mp = std::map<ll, ll>;
using Mmp = std::multimap<ll, ll>;
using Ump = std::unordered_map<ll, ll>;

// -------------------------------------------------
namespace {
using namespace std;

// # define DUMP(args...)
class Solution {
    map<string, int> s2n;
    map<int, string> res;
    void minus(map<char, int>& cur, char c) {
        auto it = cur.find(c);
        assert(it != cur.end());
        it->second -= 1;
        if (it->second == 0)
            cur.erase(it);
    }
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        DUMP(s, maxLetters, minSize, maxSize);
        for (int k = minSize; k <= maxSize; ++k) {
            map<char, int> cur;
            for (int i = 0; i < k; ++i)
                cur[s[i]] += 1;
            if (cur.size() <= maxLetters) {  // check
                auto sub = s.substr(0, k);
                s2n[sub] += 1;
                // DUMP("add", sub);
            }
            int len = s.size() - k;
            DUMP(k, len);
            for (int i = 1; i <= len; ++i) {
                // DUMP("check", sub);
                if (s[i+k-1] != s[i-1]) {
                    minus(cur, s[i-1]);
                    cur[s[i+k-1]] += 1;
                }
                // DUMP("check", cur);
                if (cur.size() <= maxLetters) {  // check
                    auto sub = s.substr(i, k);
                    s2n[sub] += 1;
                    // DUMP("add", i);
                }
            }
        }

        DUMP(s2n);
        for (auto& kv : s2n)
            res[-kv.second] = kv.first;
        DUMP(res);
        if (res.empty())
            return 0;
        return -res.begin()->first;
    }
};
}
void Init() {}
void Solve() {
    string s;
    int maxLetters;
    int minSize;
    int maxSize;
    std::cin >> s >> maxLetters >> minSize >> maxSize;
    Solution sol;
    auto r = sol.maxFreq(s, maxLetters, minSize, maxSize);
    DUMP(r);
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
    ll t = 1;
    std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
