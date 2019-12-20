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
using Umap = std::unordered_map<ll, ll>;

// -------------------------------------------------
// n(n+1) >= 2(b-a)
const ll N = 1e6 + 9;
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
ll a, b, c;
void Init() {}
bool Check(ll i, const Vec& vec) {
    for (auto v : vec) {
        auto q = i + v;
        // assert(q%4==0 || (q+1)%4==0);
        auto t = q*(q+1) - 2*c;
        if (t >= 0) {
            col(q);
            return true;
        }
    }
    return false;
}
void Solve() {
    std::cin >> a >> b;
    if (a > b) {
        std::swap(a, b);
    }

    c = b - a;
    auto d = 2 * c;
    auto x = (ll)sqrt(d) - 1;
    auto m = x % 4;
    if (m > 0)
        x -= m;
    x -= 4;
    if (x < 0)
        x = 0;
    for (ll i = x; ; i += 4) {
        if (c % 2 == 0) {  // choose 3/4, or mod 4 == 0/3
            Vec vec{0,3};
            if (Check(i, vec))
                return;
        } else {  // mod 4 == 1/2
            Vec vec{1,2};
            if (Check(i, vec))
                return;
        }
    }
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
    Init();
    ll t;
    std::cin >> t;
    for0(i, t) Solve();
#else
    Init();
    Solve();
#endif

    return 0;
}
