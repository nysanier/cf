#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define Dwn(i, x, y) for (int i = x; i >= y; i --)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 110000;
char s[N]; bool fl;
int l, ans[N], a[N];
int main()
{
	scanf ("%s", s + 1), l = strlen(s + 1);
	Rep(i, 1, l) a[i] = s[i] - '0';
	Rep(i, 1, l / 2) {
		// if (a[i - 1] > 1) { fl = 1; break ; }
		if (a[i - 1] == 1 && a[l - i + 1] <= a[i]) {
			ans[i] = 10 + a[l - i + 1], a[i - 1] --;
			int j = l - i;
			while (j > i && !a[j]) a[j] = 9, j --;
			a[j] --;
		} else ans[i] = a[l - i + 1], a[i] += 10 * a[i - 1];
		if (ans[i] < 0 || ans[i] == 19) { fl = 1; break ; }
		a[i] -= a[l - i + 1];
		if (a[i] < 0 || a[i] > 1) { fl = 1; break ; }
	}
	if (l % 2 == 1) {
		int x = l / 2 + 1, k = a[x - 1] * 10 + a[x];
		if (k % 2 != 0) fl = 1;
		ans[l / 2 + 1] = k / 2;
	} else if (a[l / 2]) fl = 1;
	if (fl || !ans[1]) {
		if (s[1] == '1') {
			Rep(i, 1, l) a[i - 1] = s[i] - '0';
			fl = 0; l --;
			Rep(i, 1, l / 2) {
				// if (a[i - 1] > 1) { fl = 1; break ; }
				if (a[i - 1] == 1 && a[l - i + 1] <= a[i]) {
					ans[i] = 10 + a[l - i + 1], a[i - 1] --;
					int j = l - i;
					while (j > i && !a[j]) a[j] = 9, j --;
					a[j] --;
				} else ans[i] = a[l - i + 1], a[i] += 10 * a[i - 1];
				// cout << i <<" "<<ans[i]<<endl;
				if (ans[i] < 0 || ans[i] == 19) { fl = 1; break ; }
				a[i] -= a[l - i + 1];
				if (a[i] < 0 || a[i] > 1) { fl = 1; break ; }
			}
			// cout << l << endl;
			if (l % 2 == 1) {
				int x = l / 2 + 1, k = a[x - 1] * 10 + a[x];
				if (k % 2 != 0) fl = 1;
				ans[l / 2 + 1] = k / 2;
			} else if (a[l / 2]) fl = 1;
		}
		if (fl || !ans[1]) { puts("0"); return 0; }
	}
	Rep(i, 1, l / 2) ans[l - i + 1] = max(ans[i] - 9, 0), ans[i] = min(ans[i], 9);
	// int st = 1; while (!ans[st]) st ++;
	Rep(i, 1, l) printf("%d", ans[i]); puts("");
 
	return 0;
}