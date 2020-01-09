#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (decltype(n) i = x; i < (n)+(x); ++i)
#define fornr(i, x, n) for (auto i = (n)-1+(x); i >= x; --i)
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (auto i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (auto i = y; i >= x; i -= d)
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

// -------------------------------------------------
const ll N = 1e5 + 9;
const ll INF = 1e9 + 21;
const ll MOD = 1e9 + 7;
ll n, m;
ll a[N], b[N];
void Init() {}
void Solve2() {
    Lst l;
    std::cin >> n >> m;
    for0(i, n) {
        std::cin >> a[i];
        l.push_back(a[i]);
    }
    for0(i, m) std::cin >> b[i];

    ll ans = 0;
    for0(i, m) {
        // DUMP(i, l);
        Mp mp;
        for (auto it = l.begin(); it != l.end();) {
            if (*it == b[i]) {
                l.erase(it);
                break;
            }

            mp[*it] = 0;
            it = l.erase(it);
        }
        ans += mp.size() * 2 + 1;

        Lst l2;
        forxy(j, i+1, m) {
            if (mp.find(b[j]) == mp.end()) {
                break;
            }

            l2.push_back(b[j]);
            mp.erase(b[j]);
        }
        for (auto& kv : mp) {
            l2.push_back(kv.first);
        }
        l2.splice(l2.end(), l);
        l.swap(l2);
    }

    col(ans);
}

void Solve() {
    Mp mp, mp2;
    std::cin >> n >> m;
    for1(i, n) {
        std::cin >> a[i];
        mp[a[i]] = i;
    }

    ll ans = 0;
    ll mx = 0;
    for1(i, m) {
        std::cin >> b[i];
        auto it = mp.find(b[i]);
        if (it->second > mx) {
            ll d = (it->second - mp2.size());
            ans += 2 * (d - 1) + 1;
            mx = it->second;
            // DUMP(i, d, mx);
        } else {
            ans += 1;
            // DUMP(i, 1);
        }
        mp2[it->first] = 0;
    }
    col(ans);
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
    std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
