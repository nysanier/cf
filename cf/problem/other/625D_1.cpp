#include <cstdio>
#include <cstring>
 
char s[100010];
char ans[100010];
int sum[100010];
int n;
 
bool check()
{
	for (int i = 0; i < n / 2;)
	{
		if (sum[i] == sum[n - 1 - i])
		{
			++i;
		}
		else if (sum[i] == sum[n - 1 - i] + 1)
		{
			sum[i]--;
			sum[i + 1] += 10;
		}
		else if (sum[i] == sum[n - 1 - i] + 10)
		{
			sum[n - 2 - i]--;
			sum[n - 1 - i] += 10;
		}
		else if (sum[i] == sum[n - 1 - i] + 10 + 1)
		{
			sum[i]--;
			sum[i + 1] += 10;
		}
		else
		{
			return false;
		}
	}
	for (int i = 0; i < n; ++i)
		if (sum[i] < 0)
			return false;
	if (n % 2 == 1)
	{
		if (sum[n / 2] % 2 == 1 || sum[n / 2] / 2 >= 10)
			return false;
		else
			ans[n / 2] = sum[n / 2] / 2 + '0';
	}
	for (int i = 0; i < n / 2; ++i)
	{
		int a = sum[i] / 2;
		int b = sum[i] - a;
		if (a >= 10 || b >= 10)
			return false;
		ans[i] = b + '0';
		ans[n - 1 - i] = a + '0';
	}
	ans[n] = 0;
	return ans[0] > '0';
}
 
int main()
{
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i)
		sum[i] = s[i] - '0';
	if (check())
	{
		printf("%s\n", ans);
	}
	else if (s[0] == '1')
	{
		for (int i = 0; i < n; ++i)
			sum[i] = s[i + 1] - '0';
		n--;
		sum[0] += 10;
		if (check())
		{
			printf("%s\n", ans);
		}
		else
		{
			puts("0");
		}
	}
	else
	{
		puts("0");
	}
	return 0;
}