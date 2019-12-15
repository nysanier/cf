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
// ll ans[N];
void Solve() {
    std::vector<std::map<std::string, ll>> a(4);
    std::cin >> n;
    for1(i, n) {
        std::cin >> s;
        ll x = s[0]-'0';
        ll y = s[s.size()-1]-'0';
        a[x*2+y][s] = i;
    }
    auto x00 = a[0].size();
    auto x01 = a[1].size();
    auto x10 = a[2].size();
    auto x11 = a[3].size();
    if (x01 == 0 && x10 == 0) {
        if (x00 > 0 && x11 > 0) {
            col(-1);
            return;
        }
        col(0);
        return;
    }

    Vec ans;
    if (x01 > x10 + 1) {
        int v = (x01-x10)/2;
        int sum = 0;
        for (auto& kv : a[1]) {
            auto k = kv.first;
            std::reverse(k.begin(), k.end());
            if (a[2].find(k) == a[2].end()) {
                ans.push_back(kv.second);
                sum++;
                if (sum >= v)
                    break;
            }
        }
    } else if (x10 > x01 + 1) {
        int v = (x10-x01)/2;
        int sum = 0;
        for (auto& kv : a[2]) {
            auto k = kv.first;
            std::reverse(k.begin(), k.end());
            if (a[1].find(k) == a[1].end()) {
                ans.push_back(kv.second);
                sum++;
                if (sum >= v)
                    break;
            }
        }
    } else {
        col(0);
        return;
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

#if 1
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
