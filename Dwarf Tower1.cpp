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
using namespace std;
int n , m ; 
#define LL __int64
LL a[100045];
struct node{
   int a,b; 
};
vector<node> ans[10005];
int visit[10005];
LL dfs(int k)
{
   if(visit[k] == 0 )
       visit[k] = 1;
   else 
       return a[k];
   int n = ans[k].size();
   if(n == 0 )
       return a[k];
   for(int i = 0 ;i < n ;i ++)
   { 
       int ta = ans[k][i].a;
       int tb = ans[k][i].b;
       a[k] = min(dfs(ta)+dfs(tb),a[k]);
   }
   return a[k];
}
int main()
{
        scanf("%d %d",&n,&m);
        memset(visit,0,sizeof(visit));
        for(int i =1 ;i <= n;i ++)
        {
        	ans[i].clear();
           scanf("%I64d",&a[i]);
       }
        int d, b, c; 
        for(int i =1 ;i <= m;i ++)
        {
            scanf("%d %d %d",&d,&b,&c);
            struct node temp;
            temp.a = b;
            temp.b = c; 
            ans[d].push_back(temp);
        }
        printf("%I64d\n",dfs(1));
	return 0;
}
