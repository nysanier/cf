#include <bits/stdc++.h>
// #include <bits/extc++.h>
#ifndef ONLINE_JUDGE
# include "dump.h"
#else
# define DUMP(args...)
# define LINE(e)
#endif

// abbr
#define forn(i, x, n) for (long i = x; i < n+x; ++i)
#define fornr(i, x, n) for (long i = n-1+x; i >= x; --i)  // must be signed, or 0->~0
#define for0(i, n) forn(i, 0, n)
#define for1(i, n) forn(i, 1, n)
#define for0r(i, n) fornr(i, 0, n)
#define for1r(i, n) fornr(i, 1, n)
#define forxyd(i, x, y, d) for (long i = x; i <= y; i += d)
#define foryxd(i, x, y, d) for (long i = y; i >= x; i -= d)
#define forxy(i, x, y) forxyd(i, x, y, 1)
#define foryx(i, x, y) foryxd(i, x, y, 1)
#define col(e) (std::cout << (e) << std::endl)
#define co(e) (std::cout << (e) << " ")

// type
// using ll = int32_t;
using ll = int64_t;
using Vec = std::vector<ll>;
using Deq = std::deque<ll>;
using Lst = std::list<ll>;
using Pr = std::pair<ll, ll>;
using St = std::set<ll>;
using Mst = std::multiset<ll>;
using Ust = std::unordered_set<ll>;
using Mp = std::map<ll, ll>;
using Mmp = std::multimap<ll, ll>;
using Ump = std::unordered_map<ll, ll>;

// -------------------------------------------------
void Init() {}
void ToLower(std::string& str) {
    for (auto& c : str)
        c = std::tolower(c);
}
void Solve2() {
    std::string word;
    std::getline(std::cin, word);
    ToLower(word);
    std::string text;
    std::getline(std::cin, text);
    ToLower(text);
    std::istringstream strin(text);
    ll cnt = 0;
    std::string w;
    for (ll i = 0; strin >> w; ++i)
        if (w == word)
            cnt += 1;
    if (cnt == 0) {
        col(-1);
        return;
    }
    auto p = text.find(word);
    co(cnt); col(p);
}
void Solve() {
    using namespace std;
    //定义两个字符串
    string a;
    string b;
    //用string库，调用getline, 直接读入一整行
    getline(cin,a);
    getline(cin,b);
    //转换大小写，可以都转换为大写，或者小写
    for (int i=0;i<a.length();++i){
        a[i]=tolower(a[i]);
    }
    for (int i=0;i<b.length();++i){
        b[i]=tolower(b[i]);
    }
    //因为连起来的不算，所以要在前后加几个空格，一定要是同样多的，同量减同量，等于同量
    a=' '+a+' ';
    b=' '+b+' ';
    //先看看会不会找不到，用a.find()和string::npos
    if (b.find(a)==string::npos){
        cout<<-1<<endl;
    }
    //如果找得到
    else {
        int alpha=b.find(a);
        int beta=b.find(a),s=0;//计数器初始化为0
        while (beta!=string::npos){
            ++s;//计数器
            beta=b.find(a,beta+1);
        }
        cout<<s<<" "<<alpha<<endl;//输出第一个和总共有几个
    }
    //函数返回值为0，结束整个程序
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Init();
    ll t = 1;
    // std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
