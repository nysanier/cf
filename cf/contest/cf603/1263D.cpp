#include "bits/stdc++.h"


int pre[26];
void InitUf() {
    for (int i = 0; i < 26; ++i) {
        pre[i] = i;
    }
}
int find(int x)                                                                                                         //查找根节点
{ 
    int r=x;
    while ( pre[r ] != r )                                                                                              //返回根节点 r
          r=pre[r ];
    int i=x , j ;
    while( i != r )                                                                                                        //路径压缩
    {
         j = pre[ i ]; // 在改变上级之前用临时变量  j 记录下他的值 
         pre[ i ]= r ; //把上级改为根节点
         i=j;
    }
    return r ;
}

void join(int x,int y)                                                                                                    //判断x y是否连通，
                                                                                             //如果已经连通，就不用管了 //如果不连通，就把它们所在的连通分支合并起,
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        pre[fx ]=fy;
}

 

int n;
std::set<int> all;

int main() {
    InitUf();
    // printf(">\n");
    scanf("%d", &n);
    char str[51];
    for (int i = 0; i < n; ++i) {
        std::set<int> setx;
        scanf("%s", str);
        for (auto p = str; *p != '\0'; ++p) {
            setx.insert(*p - 'a');
        }
        std::vector<int> vec(setx.begin(), setx.end());
        for (int x = 0; x < (int)vec.size(); ++x) {
            all.insert(vec[x]);
            for (int y = x + 1; y < (int)vec.size(); ++y) {
                join(vec[x], vec[y]);
            }
        }
    }

    std::set<int> res;
    for (int i = 0; i < 26; ++i) {
        auto x = find(i);
        if (all.count(x) == 0) {
            // printf("no: %c\n", x + 'a');
            continue;
        }
        res.insert(x);
    }
    printf("%d\n", (int)res.size());

    return 0;
}
