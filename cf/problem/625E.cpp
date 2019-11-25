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

#define mp make_pair
using namespace std;
const int N=1e5+10;
const int inf=2e9;
typedef pair<int,int> pii;
int gi() {
  int x=0,o=1;char ch=getchar();
  while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
  if(ch=='-') o=-1,ch=getchar();
  while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return x*o;
}
int n,m,p[N],a[N],pre[N],nxt[N],id[N];
set<pii> s;
bool cmp(int a,int b) {
  return p[a]<p[b];
}

// return: x追上y的次数
int calc(int x,int y) {
  if(x==y) return inf;  // 自己追不上自己
  int d=((p[y]-p[x]+m)%m+(y<x)*a[y])%m;  // y到x的距离, +后面那个值什么意思?
  if(d<=a[x]) return 1;  // 1次就可以追上
  if(a[x]<=a[y]) return inf;  // 1次如果追不上,那么就永远追不上了
  return (d-a[y]-1)/(a[x]-a[y])+1;  // 多少次可以追上!
}
int main() {
#ifndef ONLINE_JUDGE
  freopen("CF625E.in","r",stdin);
  freopen("CF625E.out","w",stdout);
#endif
  cin>>n>>m;
  for(int i=1;i<=n;i++) p[i]=gi()-1,a[i]=gi(),id[i]=i;
  sort(id+1,id+n+1,cmp);
  for(int i=1;i<=n;i++) pre[id[i]]=i-1?id[i-1]:id[n],nxt[id[i]]=i+1<=n?id[i+1]:id[1];
  for(int i=1;i<=n;i++) s.insert(mp(calc(i,nxt[i]),i));
  while(s.begin()->first<inf) {
    int i=s.begin()->second,j=s.begin()->first;s.erase(s.begin());
    s.erase(mp(calc(nxt[i],nxt[nxt[i]]),nxt[i]));
    s.erase(mp(calc(pre[i],i),pre[i]));
    p[i]=(p[i]+j)%m;a[i]--;
    nxt[i]=nxt[nxt[i]];pre[nxt[i]]=i;
    s.insert(mp(calc(i,nxt[i]),i));
    s.insert(mp(calc(pre[i],i),pre[i]));
  }
  printf("%d\n",s.size());
  for(auto x:s) printf("%d ",x.second);
  return 0;
}
