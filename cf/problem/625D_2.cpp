#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;
 
#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------
 
string S;
int carry[101010];
int sum[101010];
 
int decdec(int l,string& S) {
	while(1) {
		if(l>=S.size()) return 0;
		S[l]--;
		if(S[l]>=0) break;
		S[l]+=10;
		l++;
	}
	return 1;
}
 
string trytry(int L,string S) {
	int i,j;
	
	FOR(i,(L+1)/2) {
		if(L%2 && i==L/2) {
			if(S[i]%2) return "";
			sum[i]=S[i];
			if(S[i+1]==1) {
				S[i+1]=0;
				sum[i]+=10;
			}
			S[i]=0;
		}
		else {
			int low=S[i];
			
			if(S[L-1-i]!=low && S[L-1-i]!=(low+1)%10) return "";
			int hi=S[L-1-i+1];
			if(low==9 && S[L-1-i]==0 && hi==1) hi=0;
			sum[i]=hi*10+low;
			if(sum[i]>18) return "";
			
			if(S[L-1-i]>=low) S[L-1-i]-=low;
			else {
				if(S[L-1-i]==0 && low==9 && S[L-1-i+1]==1) {
					S[L-1-i]=1;
					S[L-1-i+1]=0;
				}
			}
			
			S[i]=0;
			if(hi) {
				if(decdec(i+1,S)==0) return "";
				if(decdec(L-1-i+1,S)==0) return "";
			}
		}
	}
	
	if(count(ALL(S),0)!=S.size()) return "";
	
	string R=string(L,'0');
	FOR(i,(L+1)/2) {
		if(L%2 && i==L/2) {
			R[i]+=sum[i]/2;
		}
		else {
			R[i]+=min(9,sum[i]);
			R[L-1-i]+=sum[i]-(R[i]-'0');
		}
	}
	if(R[0]=='0') return "";
	return R;
}
 
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	string S;
	cin>>S;
	int L=S.size();
	if(L==1) {
		if((S[0]-'0')%2) return _P("0\n");
		return _P("%d\n",(S[0]-'0')/2);
	}
	reverse(ALL(S));
	S+='0';
	FORR(c,S) c-='0';
	
	s=trytry(L,S);
	if(s!="") {
		cout<<s<<endl;
		return;
	}
	if(S[L-1]==1) {
		s=trytry(L-1,S);
		if(s!="") {
			cout<<s<<endl;
			return;
		}
	}
	
	cout<<0<<endl;
	
}
 
 
int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}