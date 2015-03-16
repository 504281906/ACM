#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>

#include<queue>
 
using namespace std;
#define mod 1000000007
long long  num[1200];
long long temp[20][1200];
int main(){
  int  n;
  scanf("%d",&n);
  num[1] = 1;
  for(int i = 2;i <= n;i ++)
      num[i] = num[i-1] * 10 % mod;
  for(int i = 0 ;i <= 9 ;i ++)
    temp[i][1] = i;
  for(int i = 1;i <= 9;i ++)
     for(int j = 2;j <= n;j ++)
        temp[i][j] = (temp[i][j-1] + i * num[j])%mod;
  long long  ans = 0 ;
  for(int i =0 ;i < n;i ++ )
    for(int j = 0 ;j < n;j ++)
    {
       int t;
       scanf("%1d",&t);
       ans = (ans + temp[t][n-j]*(j+1) + temp[t][n-i]*(i+1)) % mod;
    }
  printf("%lld\n",ans);
return 0;
}
