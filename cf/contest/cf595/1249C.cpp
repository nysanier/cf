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
const ll N = 1e6 + 9;
const ll INF = 1e9 + 21;
const ll MAX = 1e18;
ll n;
Vec a;
Vec b;
void Init() {
    a.push_back(1);
    for (;;) {
        auto v = *--a.end() * 3;
        a.push_back(v);
        if (v >= MAX)
            break;
    }
    auto len = a.size();
    b.resize(len);
    b[0] = a[0];
    for1(i, len-1) {
        b[i] = a[i] + b[i-1];
    }
    auto as = ToStr(a);
    auto bs = ToStr(b);
    dump(as);
    dump(bs);
}
void Solve() {
    std::cin >> n;
    auto it = std::lower_bound(a.begin(), a.end(), n);  // *it >= n
    auto itv = *it;
    dump(itv);
    if (it == a.begin()) {
        std::cout << *it << std::endl;
        return;
    }

    // try comb all the nums before it
    ll sum = 0;
    auto d = it - a.begin();
    dump(d);
    for0r(i, d) {
        dump3(i, a[i], b[i]);
        if (i == 0) {
            if (sum < n) {
                sum += a[i];
                dump4("pick", i, a[i], sum);
            } else {
                dump3("skip", i, a[i]);
            }
            continue;
        }
        if (sum + b[i] <= n) {
            sum += a[i];
            dump4("pick", i, a[i], sum);
            continue;
        }
        // sum + b[i] > n
        if (sum + b[i-1] >= n) {
            dump3("skip", i, a[i]);
        } else {
            sum += a[i];
            dump4("pick", i, a[i], sum);
        }
    }

    dump2(sum, n);
    if (sum < n) {
        sum = *it;
    }

    // output
    // for0(i, n) {
    //     std::cout << a[i] << " ";
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
    Init();
#if 1
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
