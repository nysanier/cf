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
const ll N = 60 + 9;
const ll INF = 1e9 + 21;
ll r,c;
// std::string s[N];
char s[N][N];  // 耗时与std::string无差别，都是171ms
void Init() {}
bool RowAllA(int row) {
    for0(i, c)
        if (s[row][i] == 'P') return false;
    return true;
}
bool ColAllA(int col) {
    for0(i, r)
        if (s[i][col] == 'P') return false;
    return true;
}
bool RowOneA(int row) {
    for0(i, c)
        if (s[row][i] == 'A') return true;
    return false;
}
bool ColOneA(int col) {
    for0(i, r)
        if (s[i][col] == 'A') return true;
    return false;
}
void Solve() {
    ll cntA = 0;
    std::cin >> r >> c;
    for0(i, r) {
        std::cin >> s[i];
        // cntA += std::count(s[i].begin(), s[i].end(), 'A');
        cntA += std::count(s[i], s[i]+c, 'A');
    }
    if (cntA == 0) {
        col("MORTAL");
        return;
    }

    if (cntA == r * c) {
        col(0);
        return;
    }

    if (RowAllA(0) || RowAllA(r-1) || ColAllA(0) || ColAllA(c-1)) {
        col(1);
        return;
    }

    // corner
    if (s[0][0]=='A' || s[0][c-1]=='A' || s[r-1][0]=='A' || s[r-1][c-1]=='A') {
        col(2);
        return;
    }

    // inner row/col
    for1(i, r-2) {
        if (RowAllA(i)) {
            col(2);
            return;
        }
    }
    for1(i, c-2) {
        if (ColAllA(i)) {
            col(2);
            return;
        }
    }

    // edge
    if (RowOneA(0) || RowOneA(r-1) || ColOneA(0) || ColOneA(c-1)) {
        col(3);
        return;
    }

    // inner
    col(4);
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
