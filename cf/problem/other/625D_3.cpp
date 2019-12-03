#include<cstdio>
#include<cstring>
 
int l, digit[100005];
bool a = true;
char s[100005], ans[100005];
 
void copy () {
	for (int i = 0; i < l; i++) digit[i] = s[i] - '0';
}
 
void back(int x) {
	digit[x]--;
	digit[x + 1] += 10;
}
 
bool solved(int x) {
	bool b = true;
	for (int i = x, j = l - 1; b && i <= j; i++, j--) {
	    if (i == x && digit[i] == 0) b = false;
		else if (i == j && digit[i] % 2) b = false;
		else if (i == j) ans[i] = '0' + digit[i] / 2;
		else if (digit[i] != digit[j]) b = false;
		else if (digit[i] > 9) {
			ans[i] = '9';
			ans[j] = '0' + digit[i] - 9;
		}
		else {
			ans[i] = '0' + digit[i];
			ans[j] = '0';
		}
	}
	if (b) printf("%s\n", ans + x);
	return b;
}
 
int main() {
	scanf("%s", s);
	l = strlen(s);
	if (s[0] == '1' && l > 1) {
		copy();
		back(0);
		for (int i = 1, j = l - 1; a && i <= j; i++, j--) {
			if (digit[j] < 0 && i != j) back(j - 1);
			if (digit[i] == digit[j]) l = l;
			else if (digit[i] == digit[j] + 10) back(j - 1);
			else if (digit[i] == digit[j] + 1 && i != j - 1) back(i);
			else if (digit[i] == digit[j] + 11) {
				back(i);
				if (j - 1 != i) back(j - 1);
			}
			else a = false;
			if (digit[i] < 0 || digit[j] > 18 || digit[j] < 0 || digit[i] > 18) a = false;
		}
		if (a && solved(1)) {
			scanf("\n");
			return 0;
		}
		a = true;
	}
	copy();
	for (int i = 0, j = l - 1; a && i <= j; i++, j--) {
		if (digit[j] < 0 && i != j) back(j - 1);
		if (digit[i] == digit[j]) digit[i] = digit[j];
		else if (digit[i] == digit[j] + 10) back(j - 1);
		else if (digit[i] == digit[j] + 1 && i != j - 1) back(i);
		else if (digit[i] == digit[j] + 11) {
			back(i);
			if (j - 1 != i) back(j - 1);
		}
		else a = false;
		if (digit[i] < 0 || digit[j] > 18 || digit[j] < 0 || digit[i] > 18) a = false;
	}
	if (!a || !solved(0)) printf("0\n");
	scanf("\n");
	return 0;
}