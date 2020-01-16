#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (long i = x; i < n+x; ++i)
#define fornr(i, x, n) for (long i = n-1+x; i >= x; --i)  // must be signed, or 0->~0
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (long i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (long i = y; i >= x; i -= d)
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

// 20ms/1.41MB
// 24ms/1.27MB  用了std::hash<std::string> 之后内存是稍微小了一点，可能规模太小没有体现出来吧，
// -------------------------------------------------
const ll N = 20 + 9;
std::string src, dst;
std::multimap<std::string, std::string> mmp;
// std::unordered_set<std::string> st;
std::unordered_set<size_t> st;
std::hash<std::string> hs;
void Init() {}
void Bfs() {
    using Pr = std::pair<ll, std::string>;
    std::queue<Pr> q;
    q.push({0, src});
    // st.insert(src);
    st.insert(hs(src));
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        if (t.second == dst) {
            col(t.first);
            return;
        }
        // DUMP(t.first, t.second);
        auto nf = t.first+1;
        if (nf > 10) continue;
        for (auto& kv : mmp) {
            for (std::string::size_type p1 = 0;;) {
                auto p2 = t.second.find(kv.first, p1);
                if (p2 == t.second.npos) break;
                auto ns = t.second.substr(0, p2) + kv.second + t.second.substr(p2+kv.first.size());
                p1 = p2 + 1;
                // if (st.find(ns) == st.end()) {
                auto hsv = hs(ns);
                if (st.find(hsv) == st.end()) {
                    st.insert(hsv);
                    // st.insert(ns);
                    q.push({nf, ns});
                }
                // DUMP("=", nf, ns);
            }
            
        }
    }

    col("NO ANSWER!");
}
void Solve() {
    std::cin >> src >> dst;
    std::string a, b;
    while (std::cin >> a >> b) {
        mmp.insert({a,b});
    }
    Bfs();
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
    // std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
