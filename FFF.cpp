#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<climits>
#include<queue>
 
using namespace std;
int n , m ;
struct node{
    int a,b,l,c;
}a[100005];
int f[10005];
int hs[10005];
int cmp(struct node a ,struct node b)
{
    if(a.l == b.l)
    {
        return a.c < b.c ;
    }
    return a.l < b.l;
}
int find(int x)
{
   return   x == f[x]?x:f[x] = find(f[x]);
}
int main(){
 
    while(scanf("%d %d",&n,&m) != EOF){
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for(int i = 1;i <= n; i ++)
            f[i] = i ;
        for(int i =1 ;i <= m;i ++)
        {
            scanf("%d %d %d %d",&a[i].a,&a[i].b,&a[i].l,&a[i].c);                            
        }
        sort(a+1,a+1+m,cmp);
        int sumc,suml;
        sumc = suml = 0 ;
        for(int i = 1;i <= m;i ++)
        {
            int ta = find(a[i].a);
            int tb = find(a[i].b);
            if(ta != tb)
            {
                f[tb] = ta;
                sumc += a[i].c ;
                suml += a[i].l ;
            }
        }
        int ok = 0 ;
        memset(hs,0,sizeof(hs));
        for(int i =1;i <= n;i ++)
        {
            hs[find(i)] ++ ;
            if(hs[find(i)] == n)
                ok = 1;
        }
        if(ok)
            printf("%d %d\n",suml,sumc);
        else printf("-1 -1\n");
    }
    return 0 ;
}
