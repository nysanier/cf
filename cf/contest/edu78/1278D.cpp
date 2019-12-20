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
const ll N = 5e5 + 9;
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
// union and find
struct UnionFind {
    int* p = nullptr;  // for local var

    // all point to self
    UnionFind() {
        p = new int[N];  // root
        for (int i = 0; i < N; ++i) {
            p[i] = i;  // first point to self
        }
    }

    // find the root of x
    int Find(int x) {
        int r = x;
        while (p[r] != r) {
            r = p[r];
        }

        // zip all the element begin x and root
        int i = x;
        while (i != r) {
            int tmp = p[i];
            p[i] = r;  // point to root
            i = tmp;
        }
        return r;
    }

    void Merge(int x, int y) {
        int rx = Find(x);
        int ry = Find(y);
        if (rx != ry) {
            p[rx] = ry;  // root1 point root2, so all point to root2
        }
    }
};

ll n;
Pair a[N];
void Init() {}
void Solve() {
    std::cin >> n;
    for0(i, n) {
        std::cin >> a[i].first >> a[i].second;
    }
    std::sort(a, a+n);

    ll cnt = 0;
    UnionFind uf;
    for0(i, n-1) {
        forxy(j, i+1, n-1) {
            if (a[j].first > a[i].second) break;
            if (a[j].second > a[i].second) {
                uf.Merge(i, j);
                cnt += 1;
                if (cnt > n-1) {
                    col("NO");
                    return;
                }
            }
        }
    }

    Set setx;
    for0(i, n) {
        setx.insert(uf.Find(i));
    }
    assert(setx.size() > 0);
    if (setx.size() > 1) {
        col("NO");
        return;
    }

    col("YES");
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
