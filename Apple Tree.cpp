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

using namespace std;
int n , m;  
int ans[300][300];
int p(int x)
{
   int t = 1;
   for(int i =1;i <= x;i ++)
      t = t * 2; 
   return t;
}
int count(int i , int j)
{
   int sum = ans[i-1][j]+ans[i][j-1] + ans[i+1][j] + ans[i][j+1];
   return p(sum);
}
int main(){
   int t; 
   scanf("%d",&t);
   while(t--)
   {
      int n , m ; 
      scanf("%d %d",&n,&m);
      memset(ans,0,sizeof(ans));
      for(int i =1;i <= n;i ++)
      {
        if(i % 2 == 1)
        {
          for(int j =1;j <= m;j ++)
          {
              if(j % 2 == 0 )
              {
                 ans[i][j] = 1; 
              }
          }
        }else{
          for(int j  = 1;j <= m;j ++)
              if(j % 2 == 1 )
                  ans[i][j] = 1;
        }
      }
      LL rans = 0 ; 
      for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= m;j ++)
        {
           if(ans[i][j] == 0)
           {
              rans += count(i,j);
           }
        }
      printf("%I64d\n",rans);
   }
    
  return 0;
}
