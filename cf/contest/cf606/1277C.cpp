#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include <dump.h>
#else
# define DUMP(args...)
#endif

// abbr
#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)
#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

// type
using ll = int32_t;
// using ll = int64_t;
using Vec = std::vector<ll>;
using Pair = std::pair<ll, ll>;
using Set = std::set<ll>;
using Map = std::map<ll, ll>;
using Hash = std::unordered_map<ll, ll>;

// -------------------------------------------------
const ll N = 2e5 + 9;
const ll INF = 1e9 + 21;
ll n;
std::string s;
// onetwonetwooneooonetwooo
// tttttwooooooo 需要去掉t或者o，看数量
// ooooooneeeee 需要去掉数量少的o或者e
// tttwoooone 怎么去？需要把所有的o去掉？其实去掉w和n也是可以的，就看o的个数
void Solve() {
    Vec vec1;
    std::cin >> s;
    std::string::size_type p1 = 0;
    for (;;) {
        auto p2 = s.find("twone", p1);
        if (p2 == s.npos) break;
        else {
            s[p2+2] = '.';
            vec1.push_back(p2+2+1);
            p1 = p2;
        }
    }

    p1 = 0;
    for (;;) {
        auto p2 = s.find("two", p1);
        if (p2 == s.npos) break;
        else {
            s[p2+1] = '.';
            vec1.push_back(p2+1+1);
            p1 = p2;
        }
    }

    p1 = 0;
    for (;;) {
        auto p2 = s.find("one", p1);
        if (p2 == s.npos) break;
        else {
            s[p2+1] = '.';
            vec1.push_back(p2+1+1);
            p1 = p2;
        }
    }

    // output
    auto ans = vec1.size();
    col(ans);
    for0(i, ans) {
        co(vec1[i]);
    }
    col("");
    DUMP(s);
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

#if 1
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
