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
ll n, sx, sy;
// ll x[N], y[N];
ll dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
ll px[4], py[4];
ll sum[4] = {0,};
void Solve() {
    std::cin >> n >> sx >> sy;
    DUMP(n, sx, sy);
    for0(i, 4) {
        px[i] = sx + dir[i][0];
        py[i] = sy + dir[i][1];
    }
    ll x2, y2;
    for0(k, n) {
        std::cin >> x2 >> y2;
        ll x1 = sx, y1 = sy;
        if (x2 < x1) std::swap(x2, x1), std::swap(y2, y1);
        for0(i, 4) {
            auto pxi = px[i];
            auto pyi = py[i];
            if (pxi >= x1 && pxi <= x2) {
                if (pyi >= y2 && pyi <= y1) {
                    sum[i]++;
                    continue;
                }
                if (pyi >= y1 && pyi <= y2) {
                    sum[i]++;
                    continue;
                }
            } 
        }
    }
    std::vector<Pair> vec;
    for0(i, 4) {
        vec.push_back({-sum[i], i});
    }
    std::sort(vec.begin(), vec.end());
    col(-vec[0].first);
    auto idx = vec[0].second;
    co(px[idx]);
    co(py[idx]);
    col("");

    // output
    // for0(i, n) {
    //     co(a[i]);
    // }
    // col("");
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
