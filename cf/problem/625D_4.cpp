//ITNOA
#include<bits/stdc++.h> 
 
using namespace std;
 
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
 
///#define int long long
#define rep(i, s, e) for(int i = s; i < e; i ++)
#define X first
#define Y second
 
typedef long long ll;
typedef long double ld;
 
const int maxN = 100*1000 + 15;
const int maxM = 100*100 + 5;
const int mod = 1000*1000*1000 + 7;
const int base = 701;
const int SQ = 500;
const int maxL = 17;
 
int a[maxN], b[maxN], cc[maxN];
int ans[maxN];
pair<int,int> p[19];
int n; 
 
string t;
bool check1()
{
    if(a[0] == 0) return false;
    
    int carry1 = 0, carry2 = 0;    
    if(a[0] != a[n-1] && a[0]+1 != a[n-1]) return false;
    if(a[0]+1 == a[n-1])
	carry2 = 1;
    
    ans[0] = p[a[0]].X;
    ans[n-1] = p[a[0]].Y;
 
    
    rep(i,1,(n+1)/2)
    {
	a[i] -= carry1;
	if(a[i] < 0) a[i] += 10;
 
	if(a[i] != a[n-i-1] && (a[i] + 1) % 10 != a[n-i-1])
	    return false;
 
	if(carry2 && a[i] == 9 && a[n-i-1] == 0) carry2 = 0;
	
	int tmp = carry2 * 10 + a[i]; carry2 = 0;
	if(tmp == 19) return false;
	      
	ans[i] = p[tmp].X; ans[n-i-1] = p[tmp].Y;
	tmp += carry1; carry1 = 0;
	
	if(a[i] != a[n-i-1]) carry2 = 1;
	if(tmp >= 10) carry1 = 1;
    }
    rep(i,0,n)
	b[i] = ans[n-i-1];
 
    int carry = 0;
    rep(i,0,n)
    {
	int tmp = (b[i] + ans[i]) + carry; carry = 0;
	if(tmp >= 10)
	    carry = 1, tmp -= 10;
	if(cc[i] != tmp) return false;
    }
    if(carry) return false;
    
    rep(i,0,n)
	t += char(b[i] + '0');
    return true;
}
 
bool check2()
{
    if(a[n-1] != 1 || a[0] == 9) return false;
    
    n --;
    int carry1 = 1, carry2 = 0;
    
    if(a[0] != a[n-1] && (a[0] + 1) % 10 != a[n-1]) return false;
    if((a[0]+1) % 10 == a[n-1])
	carry2 = 1;
    
    ans[0] = p[a[0]+10].X;
    ans[n-1] = p[a[0]+10].Y;
    
    rep(i,1,(n+1)/2)
    {
	a[i] -= carry1; 
	if(a[i] < 0) a[i] += 10;
	
	if(a[i] != a[n-i-1] && (a[i] + 1) % 10 != a[n-i-1])
	    return false;	
	
	if(carry2 && a[i] == 9 && a[n-i-1] == 0) carry2 = 0;
	
	int tmp = carry2 * 10 + a[i]; carry2 = 0;
	if(tmp == 19) return false;
	
	ans[i] = p[tmp].X; ans[n-i-1] = p[tmp].Y;
	tmp += carry1; carry1 = 0;
	
	if(a[i] != a[n-i-1]) carry2 = 1;
	if(tmp >= 10) carry1 = 1;
    }
 
    rep(i,0,n)
	b[i] = ans[n-i-1];
 
    int carry = 0;
    rep(i,0,n)
    {
	int tmp = (b[i] + ans[i]) + carry; carry = 0;
	if(tmp >= 10)
	    carry = 1, tmp -= 10;
	if(cc[i] != tmp) return false;
    }
    if(carry == 0) return false;
 
    rep(i,0,n)
	t += char(b[i] + '0');
    return true;
}
 
int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,0,19)
	p[i] = {i / 2, (i+1) / 2};
    string s; cin >> s;
    n = s.size();
    reverse(s.begin(), s.end());
 
    rep(i,0,n)
	cc[i] = a[i] = s[i] - '0';
    
    if(check1()) { cout << t << endl; return 0; }
    rep(i,0,n)
	a[i] = s[i] - '0';
    if(check2()) { cout << t << endl; return 0; }
 
    cout << 0 << endl;    
    return 0;
}