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
double dp[3000][52][52];
int n, m;
double solve(int x,int y,int z)
{
       
}
void print()
{
	for(int i = 1;i <= n*m ;i ++)
	{
	    for(int j = 1; j <= n+1;j ++)
		{
			for(int s = 1; s<= m+1; s ++)
			{   printf("%lf ",dp[i][j][s]);
			}
			printf("\n");
		}
	 printf("\n");
	}
}
int main(){
  int t; 
  scanf("%d",&t);
  while(t--)
  {
	scanf("%d %d",&n,&m);
	if(n > m )
      swap(n,m);
	memset(dp,0,sizeof(dp));
	dp[1][1][1] = 1.0 ;
	for(int i = 2;i <= n*m ;i ++)
	{
	    for(int j = 1; j <= n;j ++)
		{
			for(int s = 1; s<= m; s ++)
			{
			   int k = (n*m-(i-1));
			   if(!(j == n && s ==m))
			    dp[i][j][s] += dp[i-1][j][s]*(max(0,j*s-(i-1))*1.0/k); 
			   dp[i][j][s+1] += dp[i-1][j][s] *(max(0,j*m-s*j)*1.0/k);  
			   dp[i][j+1][s] += dp[i-1][j][s] *(max(0,s*n-s*j)*1.0/k);
			   dp[i][j+1][s+1] += dp[i-1][j][s] *((n*m-(s*n+j*m-s*j))*1.0/k);
			}
		}
	}
    //print(); 
    double ans = 0.0 ; 
	for(int i = 1;i <= n*m ;i ++)
      ans += i * dp[i][n][m];
     printf("%.10lf\n",ans);
  }
return 0;
}
