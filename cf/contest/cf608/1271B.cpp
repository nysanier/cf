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
const ll N = 2e2 + 9;
const ll INF = 1e9 + 21;
ll n;
std::string s;
// ll ans[N];
void Change(char& ch) {
    if (ch == 'W') ch = 'B';
    else if (ch == 'B') ch = 'W';
    else assert(0);
}
void Solve() {
    std::cin >> n >> s;
    auto v1 = std::count(s.begin(), s.end(), 'W');
    auto v2 = std::count(s.begin(), s.end(), 'B');
    if (v1 % 2 == 1 && v2 % 2 == 1) {
        col(-1);
        return;
    }

    char ch = 'W';  // 'B' -> 'W'
    if (v2 % 2 == 1) {
        ch = 'B';  // change to odd char
    }

    Vec ans;
    for0(i, n-1) {
        if (s[i] == ch) continue;
        Change(s[i]);
        Change(s[i+1]);
        ans.push_back(i+1);
    }

    // output
    auto sz = ans.size();
    col(sz);
    for0(i, sz) {
        co(ans[i]);
    }
    col("");
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

#if 0
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
