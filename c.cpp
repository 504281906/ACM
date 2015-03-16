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
#define M 1000000007
using namespace std;
LL dp[4005][2005];
int main(){
   int T ;
   //freopen("out","w",stdout);
   scanf("%d",&T);
   for(int ca = 1; ca <= T ; ca ++)
   {
      int n , m; 
	  scanf("%d-%d",&n,&m);
	  //printf("%d %d\n",n,m);
	  int t = n + m;
	  memset(dp,0,sizeof(dp));
	  dp[1][1] = 1; 
	  for(int i = 2;i <= t;i ++)
	    for(int j = 0 ;j <= n ;j ++)
	     {
	        if(i - j < j)
			{
             if((i - 1) - j < j)
		       dp[i][j] = (dp[i][j] + dp[i-1][j])%M;
			 if((i-1) - (j-1) < (j-1))
			   dp[i][j] =(dp[i][j] + dp[i-1][j-1])% M;
			}
	     }
	  printf("Case #%d: %lld ",ca,dp[t][n]);
	  memset(dp,0,sizeof(dp));
	  dp[1][1] = 1; 
	  LL sum =0 ; 
	  for(int i = 2;i <= m+m;i ++)
	    for(int j = 0 ;j <= m ;j ++)
	     {
	        if(i - j < j)
			{
             if((i - 1) - j < j)
		       dp[i][j] = (dp[i][j] + dp[i-1][j])%M;
			 if((i-1) - (j-1) < (j-1))
			   dp[i][j] =(dp[i][j] + dp[i-1][j-1])%M;
			}
	     }
	  for(int i = m;i <= m+m -1;i ++)
		  sum = (sum+dp[i][m])%M;
	  printf("%lld\n",sum);
   }	
return 0;
}
