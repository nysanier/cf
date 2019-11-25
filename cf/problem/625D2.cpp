// C
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <new>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// using namespace std;
// typedef long long LL;
// const int N = 2e5 + 5;
 
// int a[N];
// char s[N];
// char out[N];
// int main() {
// //  cin + dig
// 	scanf("%s",s+1);
// 	int n = strlen(s+1);
// 	for(int i=1;i<=n;i++) a[i] = s[i] - '0';
// //  l,r
// 	int l = 1,r = n;
// 	if(a[l] != a[r]) {
// 		a[l] --;
// 		a[l+1] += 10;
// 		if(!a[l]) l++;
// 	}
// 	while(l <= r) {
// 		if(a[l] != a[r]) {
// 			if(a[l] >= a[r] + 10 && a[r] < 10) {
// 				a[r-1] --;
// 				a[r] += 10;
// 			}
// 			if(a[l] - 1 == a[r]) {
// 				a[l] --;
// 				a[l+1] += 10; 
// 			}
// 		}
// 		if(a[l] != a[r]) {
// 			return puts("0"),0;
// 		} else {
// 			if(l != r) {
// 				a[r] /= 2;
// 				a[l] -= a[r];
// 			} else {
// 				if(a[l] & 1) return puts("0"),0;
// 				a[l] /= 2;
// 			}
// 			if(a[l] < 0 || a[l] > 9 || a[r] < 0 || a[r] > 9) return puts("0"),0;
// 		}
// 		l ++,r --;
// 	}
// 	l = 1;
// 	if(!a[l]) l ++;
// 	for(int i=l;i<=n;i++) printf("%d",a[i]);
// }


#define ll long long 
using namespace std;
int i , j , l ,r ;
string s ;
int a[1001000] ; 
bool slv(int i , int j ,int l ,int r ){
	if (  i > j )  return l == r ; 
	s[i] += 10*l , s[j] -= r;
	if (s[i] - s[j] > 9)   s[j] += 10 , r = 1 ;
	else     r = 0 ;
	if (s[i] > s[j])  s[i]-- , l = 1 ;
	else   l = 0 ;
    if (s[i] != s[j])   return 0;
    a[i] = (s[i] + 1 ) / 2 ;
    a[j]  = s[i] / 2 ; 
    if (s[i] > 18 ||a[i] + a[j] != s[i])  return 0 ;
    return slv(i + 1 , j - 1 , l , r) ; 
}
int main(){
	cin >> s;
	int n = s.size() ; 
	for (i = 0 ; i < n ;i++)  s[i] -='0' ; 
	i = 0 , j = n - 1  , l = 0 ,r= 0;
	if (s[0] == 1 && s[0] != s[n-1])  i = 1 , l= 1 ;
	if (!slv(i,j,l,r))   cout <<0 ;
	else {
		  for (  ; i < n ; i++)    cout << a[i] ;
	} 
	return 0 ;
}

/*
both can't pass 11121=2019+9102, both get 0, that's wrong!
*/
