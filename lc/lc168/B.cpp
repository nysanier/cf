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
    std::map<int, int> mp;
    void init(vector<int>& nums) {
        for (auto n : nums)
            mp[n] += 1;
    }
    bool remove(int k) {
        // 最小有几个移除几个
        assert(mp.size() > 0);
        auto s = *mp.begin();
        mp.erase(mp.begin());
        for (int i = 1; i <= k-1; ++i) {
            auto it = mp.find(s.first+i);
            if (it == mp.end() || it->second < s.second)
                return false;
            it->second -= s.second;
            if (it->second == 0)
                mp.erase(it);
        }
        return true;
    }
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        init(nums);
        while (!mp.empty()) {
            DUMP(mp);
            if (!remove(k)) return false;
        }
        return true;
    }
};
}

void Init() {}
void Solve() {
    std::vector<int> nums;
    int n, k, t;
    std::cin >> n;
    for (int i = 0; i < n; ++ i) {
        std::cin >> t;
        nums.push_back(t);
    }
    std::cin >> k;
    Solution s;
    auto r = s.isPossibleDivide(nums, k);
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
