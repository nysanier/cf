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

// 经验教训：能用hash就不要用map，能用数组就不要用vector！！！！
// # define DUMP(args...)
// 最多10种字符，每个字符最多10种选择{0-9}，那么直接dfs暴力搜索即可
class Solution {
    vector<string> words;
    string result;
    // vector<bool> n0;  // 不能取0的字符集
    bool n0[128];
    set<char> allset;  // 所有字符集
    vector<char> all;  // 所有字符集，allset的拷贝
    // vector<bool> dup;
    bool dup[10];
    // vector<int> c2d;
    int c2d[128];
    bool flag{false};  // 是否已经找到答案
    void init(vector<string>& words, string& result) {
        // n0.resize(128);
        std::fill(n0, n0+128, false);
        for (auto& w : words) {
            n0[w[0]] = true;
            for (auto c : w) allset.insert(c);
        }
        n0[result[0]] = true;
        for (auto c : result) allset.insert(c);
        all.assign(allset.begin(), allset.end());

        // dup.resize(10);
        std::fill(dup, dup+10, false);
        // c2d.resize(128);
        // std::fill(c2d.begin(), c2d.end(), -1);
        std::fill(c2d, c2d+128, -1);

        DUMP(n0, allset, all, words, result);

        this->words.swap(words);
        this->result.swap(result);
    }
    void dump() {
        for (auto& w : words) {
            int v = 0;
            for (auto c : w) v = 10*v + c2d[c];
            DUMP(w, v);
        }
        int r = 0;
        for (auto c : result) r = 10*r + c2d[c];
        DUMP(result, r);
    }
    bool check() {
        // return false;
        int l = 0;
        for (int i = 0; i < result.size(); ++i) {
            for (auto& w : words) {
                if (w.size() > i) l += c2d[w[w.size()-1-i]];
            }
            int r = c2d[result[result.size()-1-i]];
            if (l % 10 != r) {
                return false; 
            }
            l /= 10;
        }
        return l == 0;
    }
    void dfs(size_t k) {
        if (flag) return;
        if (k == all.size()) {
            if (check()) flag = true;
            return;
        }
        for (int i = 0; i <= 9; ++i) {
            if (i == 0 && n0[all[k]]) continue;
            if (dup[i]) continue;
            dup[i] = true;
            c2d[all[k]] = i;
            // DUMP("try", k, all[k], i);
            dfs(k+1);
            if (flag) return;
            c2d[all[k]] = -1;
            dup[i] = false;
        }
    }
public:
    bool isSolvable(vector<string>& words, string result) {
        init(words, result);
        dfs(0);
        if (flag) {
            dump();
        }
        return flag;
    }
};
}

int n;
vector<string> words;
string result;
void Init() {}
void Solve() {
    std::cin >> n;
    std::string str;
    for (int i = 0; i < n; ++i) {
        std::cin >> str;
        words.push_back(str);
    }
    std::cin >> result;

    Solution s;
    auto r = s.isSolvable(words, result);
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
