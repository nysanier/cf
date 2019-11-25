#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
 
#define FIO ios::sync_with_stdio(false); cin.tie(nullptr);
const int INF = 0x3f3f3f3f;
const int dr[4][2] = {{0, 1}, {0, -1}, { -1, 0}, {1, 0}};
 
string s;
char ans[1000010];
int sum[1000010], n;
bool check()
{
    for (int i = 0; i < (n >> 1);)
    {
 
        int l = i, r = n - 1 - i;
        if (sum[l] == sum[r])
            i++;
        else if (sum[l] == sum[r] + 1 || sum[l] == sum[r] + 11) 
        {
            sum[l]--;
            sum[l + 1] += 10;
        }
        else if (sum[l] == sum[r] + 10) 
        {
            sum[r - 1]--;
            sum[r] += 10;
        }
        else 
            return false;
    }
    if (n % 2)
    {
        if (sum[n >> 1] % 2 == 1 || sum[n >> 1] > 18 || sum[n >> 1] < 0)
            return false;
        ans[n >> 1] = (sum[n >> 1] >> 1) + '0';
    }
    for (int i = 0; i < (n >> 1); i++)
    {
        if (sum[i] > 18 || sum[i] < 0)
            return false;
        ans[i] = ((sum[i] + 1) >> 1) + '0';
        ans[n - i - 1] = ((sum[i]) >> 1) + '0';
    }
    return ans[0] > '0';
}
int main()
{
    cin >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        sum[i] = s[i] - '0';
    if (check())
    {
        cout << ans << endl;
        return 0;
    }
    if (s[0] == '1' && n > 1) 
    {
        for (int i = 0; i < n; i++)
            sum[i] = s[i + 1] - '0';
        sum[0] += 10;
        n--;
        if (check())
            cout << ans << endl;
        else 
            cout << 0 << endl;
    }
    else
        cout << 0 << endl;
}