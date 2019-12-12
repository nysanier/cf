#include <bits/stdc++.h>
#include <bits/extc++.h>

// abbr
#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)
#define forxy(i, x, y) for (auto i = x; i <= y; ++i)
#define foryx(i, x, y) for (auto i = y; i >= x; --i)
#define PB push_back
#define FI first
#define SE second

// type
// using ll = int32_t;
using ll = int64_t;
using Vec = std::vector<ll>;
using Pair = std::pair<ll, ll>;
using Set = std::set<ll>;
using Map = std::map<ll, ll>;
using Hash = std::unordered_map<ll, ll>;

// debug
template<typename C>
std::string ToStr(const C& c) {
    std::string ret("{");
    for (auto v : c)
        ret += std::to_string(v) + ",";
    ret += "}";
    return ret;
}
template<typename T1, typename T2>
std::string ToStr(const std::map<T1, T2>& c) {
    std::string ret("{");
    for (auto& kv : c)
        ret += "<" + std::to_string(kv.first) + "," + std::to_string(kv.second) + ">,";
    ret += "}";
    return ret;
}
template<typename... Args>
std::string format(const std::string& fmt, Args... args) {
    auto sz = ::snprintf(nullptr, 0, fmt.c_str(), args...);  // effective char size
    std::string buf(sz, '?');
    ::snprintf(&buf[0], sz + 1, fmt.c_str(), args...);  // len include '\0'
    return buf;
}
#ifndef ONLINE_JUDGE
# define PRE() (std::clog << "***DEBUG*** ")
# define POST() std::endl
# define dbg(fmt, args...) (PRE() << format(fmt, ##args) << POST())
# define VAR(e) (#e "=") << (e) << (",")
# define VAR2(e1,e2) VAR(e1) << VAR(e2)
# define VAR4(e1,e2,e3,e4) VAR2(e1,e2) << VAR2(e3,e4)
# define dump(e) (PRE() << VAR(e) << POST())
# define dump2(e1,e2) (PRE() << VAR2(e1,e2) << POST())
# define dump3(e1,e2,e3) (PRE() << VAR2(e1,e2) << VAR(e3) << POST())
# define dump4(e1,e2,e3,e4) (PRE() << VAR4(e1,e2,e3,e4) << POST())
# define dump5(e1,e2,e3,e4,e5) (PRE() << VAR4(e1,e2,e3,e4) << VAR(e5) << POST())
# define dump6(e1,e2,e3,e4,e5,e6) (PRE() << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << POST())
# define dump7(e1,e2,e3,e4,e5,e6,e7) (PRE() << VAR4(e1,e2,e3,e4) << VAR2(e5,e6) << VAR(e7) << POST())
#else
# define dbg(fmt, args...)
# define dump(e)
# define dump2(e1,e2)
# define dump3(e1,e2,e3)
# define dump4(e1,e2,e3,e4)
# define dump5(e1,e2,e3,e4,e5)
# define dump6(e1,e2,e3,e4,e5,e6)
# define dump7(e1,e2,e3,e4,e5,e6,e7)
#endif

// -------------------------------------------------
const ll N = 2e5 + 9;
const ll INF = 1e9 + 21;
ll n, k;
std::string s;
void Solve() {
    std::cin >> n >> k;
    std::cin >> s;
    std::string ks, t;
    for0(i, k) {
        std::cin >> t;
        ks.append(t);
    }
    Vec vec;
    std::string::size_type p = 0;
    vec.push_back(-1);
    for (;;) {
        auto p2 = s.find_first_not_of(ks, p);
        // dump(p2);
        if (p2 == s.npos) {
            vec.push_back(s.size());
            break;
        }
        vec.push_back(p2);
        p = p2 + 1;
    }
    // auto vecstr = ToStr(vec);
    // dump(vecstr);
    Vec ans;
    for1(i, vec.size()-1) {
        auto d = vec[i] - vec[i-1] - 1;
        if (d > 0) {
            ans.push_back(d);
        }
    }
    // auto ansstr = ToStr(ans);
    // dump(ansstr);
    ll sum = 0;
    for(auto v : ans) {
        sum += (v * (v+1)) / 2;
    }
    // output
    // for0(i, n) {
    //     std::cout << ans[i] << " ";
    // }
    std::cout << sum << std::endl;
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

#if 0
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
