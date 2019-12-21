#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include <dump.h>
#else
# define DUMP(args...)
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

/*
设count(x)为包含x的路径数量
x分为奇偶来讨论：
  奇数：x|2x,2x+1|4x,4x+1,4x+2,4x+3|8x,8x+1...8x+7包含x，即ax+[0,a),a取2^i(i>=0)包含x
  偶数: x,x+1|2x,2x+1,2x+2,2x+3|4x,4x+1...4x+7包含x，即ax+[0,2a),a取2^i(i>=0)包含x
另外奇偶性相同的两个数，x和x+2，count(x)>=count(x+2)，如何证明？
根据上述讨论：
  x与x+2，同奇偶，count(x)随着x的增大而变小，或者说非递增，可以考虑二分来找
  count(x)>=k要求x最大，那么就是在奇偶两条路径上分别找到最大，然后取一个最大值
  n可能在ax+[0,2a)中间，但是没有关系，x越大，被n影响的数越多，也就是count(x)越小，还是满足非递增
*/
// -------------------------------------------------
const ll N = 1e6 + 9;
const ll INF = 1e9 + 21;
ll n, k;
ll Count(ll x) {
    assert(x > 0);
    ll sum = 0;
    ll a;
    if (x%2 == 1) a = 1;
    else a = 2;
    while (x <= n) {
        sum += std::min(n-x+1, a);  // 每一轮，有a，可能n在ax+[0,a)中间
        a *= 2;
        x *= 2;  // x <<= 1
    }
    return sum;
}
ll SearchOdd() {
    ll l = 0;  // 2*l+1 >= k
    ll r = n&1 ? (n-1)/2 : n/2-1;
    while (l < r) {
        ll m = (l + r) / 2;
        if (Count(m * 2 + 1) >= k) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return 2*(l-1)+1;
}
ll SearchEven() {
    ll l = 1;
    ll r = n&1 ? (n-1)/2 : n/2;
    while (l < r) {
        ll m = (l + r) / 2;
        if (Count(m * 2) >= k) {
            l = m + 1;
        }
        else {
            r = m;
        }
    }
    return 2*(l-1);
}
void Solve() {
    std::cin >> n >> k;
    if (Count(n) >= k) {
        col(n);
        return;
    }
    if (n > 1 && Count(n-1) >= k) {
        col(n-1);
        return;
    }

    auto cnt1 = Count(1);
    assert(cnt1 >= k);
    auto odd = SearchOdd();
    auto even = SearchEven();
    DUMP(odd, even);
    col(std::max(odd, even));

    // n = 6;
    // for1(i, n) {
    //     auto cnt = Count(i);
    //     DUMP(i, cnt);
    // }
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
