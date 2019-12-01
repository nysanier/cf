#include <bits/stdc++.h>
#include <bits/extc++.h>

#define for0(i, n) for (auto i = decltype(n)(0); i < n; ++i)
#define for1(i, n) for (auto i = decltype(n)(1); i <= n; ++i)
#define for0r(i, n) for (auto i = n - 1; i >= 0; --i)
#define for1r(i, n) for (auto i = n; i >= 1; --i)

using ll = long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
const int N = 1e5 + 9;

int n;
int a[N];

void Solve() {
    scanf("%d", &n);
    for0(i, n) {
        scanf("%d", a + i);
    }

    std::vector<size_t> ans;
    std::set<int> set_day;
    std::set<int> set_cur;
    for0(i, n) {
        const int ai = a[i];
        assert(ai != 0);
        if (ai > 0) {
            if (set_day.count(ai) == 0u) {
                set_day.insert(ai);
                set_cur.insert(ai);
                continue;
            }

            // prepare for the next day
            if (set_cur.size() > 0u) {  // failed, someone not leave today
                puts("-1");
                return;
            }

            ans.push_back(set_day.size());
            set_day.clear();
            set_day.insert(ai);
            set_cur.insert(ai);
            continue;
        }

        // leave
        if (ai < 0) {
            // no enter
            if (set_cur.count(-ai) == 0u) {
                puts("-1");
                return;
            }

            set_cur.erase(-ai);

            // begin a new day
            if (set_cur.size() == 0u) {
                ans.push_back(set_day.size());
                set_day.clear();
            }
        }
    }

    // finally, someone not leave
    if (set_cur.size() > 0) {
        puts("-1");
        return;
    }

    if (set_day.size() > 0u)
        ans.push_back(set_day.size());

    printf("%d\n", (int)ans.size());
    for (auto& v : ans) {
        printf("%d ", (int)v * 2);
    }
    printf("\n");
}

// 1 -1 2 1 -1 -2
int main() {
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
