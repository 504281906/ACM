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
#define LL long long
#define maxn (1 << 21)
using namespace std;
LL hs[maxn + 100];
struct node{
  int x;
  LL v;
}add[maxn + 100];
int a[50];
int main(){
   int n , m ;
   int T;
   scanf("%d",&T);
   for(int ca = 1; ca <= T ;ca ++)
   {
       scanf("%d %d",&n,&m);
       for(int i = 1;i <= n;i ++)
       {
          scanf("%d",&a[i]);
       }
       memset(hs,0,sizeof(hs));
       for(int i = 1;i <= n;i ++)
       {
         int t = 0 ;
         for(int j = 0 ;j <= maxn ;j ++)
         {
           if(hs[j] != 0 )
           {
             t ++;
             add[t].x = j^a[i];
             add[t].v = hs[j];
           }
         }
         hs[a[i]] += 1; 
         for(int j = 1;j <= t ;j ++)
         {
           hs[add[j].x] += add[j].v;
         }
       }
       LL sum = 0 ;
       for(int i = m ;i <= maxn;i ++)
       {
           sum += hs[i]; 
       }
       if(m == 0 )
           sum ++ ; 
       printf("Case #%d: %I64d\n",ca,sum);
   }
return 0;
}
