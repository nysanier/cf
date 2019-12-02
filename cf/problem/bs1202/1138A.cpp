#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
const int N = 1e5 + 9;

int n;
int a[N];

void Solve() {
    scanf("%d", &n);
    for0(i, n) scanf("%d", a + i);
    a[n] = 9;  // sentry
    int v = a[0];
    int sum = 1;
    std::vector<pii> res;
    for1(i, n) {
        if (a[i] == v) {
            sum += 1;
            continue;
        }

        res.push_back({v, sum});
        v = a[i];
        sum = 1;
    }

    // for0(i,res.size()) {
    //     printf("%d] %d: %d\n", (int)i, res[i].first, res[i].second);
    // }

    std::set<int> ans;
    for (int i = 1; i < (int)res.size(); ++i) {
        int x = std::min(res[i].second, res[i-1].second);
        ans.insert(x);
    }

    // for (auto v : ans) {
    //     printf("%d\n", v);
    // }

    // get the max one
    int rb = *(--ans.rbegin().base());
    // int rb = *(--ans.end());  // so why not use the --end()?
    // printf("rb = %d\n", rb);
    printf("%d\n", rb * 2);
}

int main() {
/*
1(begin)   2   end
               it
          rit
it = rit.base();
rit = reverse_iterator(it);
it seem to be:
    rbegin().base() -> end()
    begin().base() -> rend()
*/
    // https://en.cppreference.com/w/cpp/iterator/reverse_iterator/base
    // The base iterator refers to the element that is next to the element the reverse_iterator is currently pointing to.
    // std::set<int> setx;
    // setx.insert(1234);
    // auto rit = setx.rbegin();
    // printf("rit = %d\n", *rit);
    // auto it = rit.base();  // it's end() iterator
    // // printf("it = %d\n", *it);
    // printf("it2 = %d\n", *--it);  // get the last one

#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

#if 0
    int t;
    scanf("%d", &t);
    for0(i, t) Solve();
#else
    Solve();
#endif

    return 0;
}
