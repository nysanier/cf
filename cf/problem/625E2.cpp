#include <bits/stdc++.h>
#define maxn 100009
#define inf 1000000000
#define mk make_pair
using namespace std;
int p[maxn], a[maxn], pos[maxn], m, n, ri[maxn], le[maxn];
set<pair<int, int>> st;
inline bool cmp(const int& A, const int& B) { return p[A] < p[B]; }
// get distance beteewn adjacent frogs
int getdis(int x, int y) {
    if (x == y) return inf;
    int d = (p[y] - p[x] + m) % m;
    if (y < x) d = (d + a[y]) % m;
    if (d <= a[x]) return 1;
    if (a[x] <= a[y]) return inf;
    return (d - a[y] - 1) / (a[x] - a[y]) + 1;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", p + i, a + i), pos[i] = i, p[i]--;
    sort(pos + 1, pos + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        ri[pos[i]] = pos[i + 1], le[pos[i]] = pos[i - 1];
    ri[pos[n]] = pos[1], le[pos[1]] = pos[n];
    for (int i = 1; i <= n; i++) st.insert(mk(getdis(i, ri[i]), i));
    while (1) {
        if (st.begin()->first == inf) break;
        int u = st.begin()->second;
        st.erase(st.begin());
        st.erase(mk(getdis(ri[u], ri[ri[u]]), ri[u]));
        if (!st.empty()) st.erase(mk(getdis(le[u], u), le[u]));
        p[u] += getdis(u, ri[u]), p[u] %= m, a[u]--;
        ri[u] = ri[ri[u]], le[ri[u]] = u;
        st.insert(mk(getdis(le[u], u), le[u])),
            st.insert(mk(getdis(u, ri[u]), u));
    }
    printf("%lu\n", st.size());
    for (set<pair<int, int>>::iterator it = st.begin(); it != st.end(); it++)
        printf("%d ", it->second);
    return 0;
}
