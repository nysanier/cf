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

using namespace std;
const int N = 30 + 9;
bool  firstwrite;
ll f[N][N];
ll root[N][N];
/*
【任务一】采用动态规划方法计算最大分值
本题可以采用动态规划方法来解决，具体如下：
设f[i, j]为顶点i . . 顶点j所组成的子树的最大分值。若f[i, j] = -1，则表明最大分值尚未计算出。
f(i,j)={1 (i>j) ; 顶点i的分数 (i=j) ; max(f{i,k-1}*f{k+1,j}+顶点i的分数 (i<j) 『k取i～j』)
root[i, j]——顶点i..顶点j所组成的子树达到最大分值时的根编号。当i = j时，root[i, i] := i。
由于问题没有明显的阶段特征，而是呈现为非线性的树形结构，因此，我们采用后序遍历的顺序来计算状态转移方程。计算过程如下：
*/
ll search(int L, int r)    // 递归计算f[L][r]
{
    int  k;
    ll  now;    // 当前分值
    if (L > r) return 1;
    if (f[L][r]== -1)     // 若尚未计算出顶点L..顶点r对应子树的最高分值
    for (k=L; k<=r; k++) {     // 穷举每一个可能的子根k
        now = search(L, k-1) * search(k+1, r) + f[k][k];  
        // 计算以k为根的子树的分值
        if(now > f[L][r])  {
        //若该分值为目前最高，则记入状态转移方程，并记下子根}
            f[L][r] = now; 
            root[L][r] = k;
        }
    }
    return  f[L][r];   // {返回顶点L..顶点r对应子树的最高分值}
}
/*
【任务二】输出加分二叉树的前序遍历
递归调用search(1, n)后得出的way给出了加分二叉树的结构，其中way[i, j]为该树中顶点i..顶点j的根序号。由于二叉树中序遍历的顺序为1..n，因此，1..way[i, j]-1为左子树，way[i, j] + 1 .. j为右子树。现按照根→左子树→右子树的顺序对加分二叉树进行前序遍历。
注意：由于数字之间用空格隔开，而第一个数字前没有空格，因此，设firstwrite为首数字标志。一旦输出了第一个数字，firstwrite设为false，表明在输入新的数字前需要加空格。
由此，得出前序遍历加分二叉树的算法：
*/
// 前序遍历顶点L..顶点r对应的子树
void  preorder(int L, int r)
{
    if (L > r)  return;
    if (firstwrite)
        firstwrite = false;
    else
        cout<<' ';      // 顶点间用空格分开
    cout << root[L][r];             // 输出子树的根
    preorder(L, root[L][r]-1);     // 前序遍历左子树
    preorder(root[L][r]+1, r);     // 前序遍历右子树
}
/*
【任务三】主程序 有了search函数和preorder过程，就不难得出主程序了：
*/
void Solve() {
    int n, i, j;
    cin >> n;    // 读顶点数
    for (i=1; i<=n; i++)      // 状态转移方程初始化
        for (j=i; j<=n; j++)
            f[i][j] = -1;
    for (i=1; i<=n; i++) {
        cin >> f[i][i];       // 读顶点i的分值
        root[i][i] = i;        // 顶点i单独成一棵子树
    }
    cout << search(1, n) << endl;      // 计算和输出最高加分
    firstwrite = true;                   // 设立首顶点标志
    preorder(1, n);                       // 前序遍历二叉树
}
// -------------------------------------------------

int main() {
#ifndef ONLINE_JUDGE
    ::freopen("../input.txt", "r", stdin);
#endif

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // Init();
    ll t = 1;
    // std::cin >> t;
    for0(i, t) Solve();

    return 0;
}
