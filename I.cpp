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
LL dp[1004][1004];
int p[1005];
  int n , m ; 
LL ans(int i , int j)
{
    if(j > m )
      return -2LL*1e9;
    return dp[n][m] - dp[i-1][m] - dp[n][j-1] + dp[i-1][j-1]; 
}
int main()
{
  int t; 
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&m);
    memset(dp,0,sizeof(dp));
    memset(p,0,sizeof(p));
    int temp ;
    for(int  i =1;i <= n;i ++)
    {
      int sum = 0 ; 
      for(int j =1;j <= m;j ++)
      {
         scanf("%d",&temp);
         sum += temp;
         dp[i][j] = dp[i-1][j] + sum;
         if(temp < 0)
             p[i]++;
      }
    }
    LL a = max(ans(n,p[n]+1),1LL*temp);
    temp = p[n+1];
    for(int i = n-1;i >= 1;i --)
    {
       for(int j = p[i+1]+1;j <= p[i]+1;j ++)
       {
          a = max(a,ans(i,j));
       }
    }
    printf("%lld\n",a);
  }
  
return 0;
}
