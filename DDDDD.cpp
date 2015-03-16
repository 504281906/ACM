#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int LL;

LL dp[1<<18][100],fact[20];
char str[20];
int n,m,cnt[20];

int main()
{
  scanf("%s%d",str,&m);
  n=strlen(str);
  for(int i=0;i<n;i++) cnt[str[i]-'0']++;
  dp[0][0]=1;fact[0]=1;
  for(int i=1;i<20;i++) fact[i]=fact[i-1]*i;
  for(int i=0;i<(1<<n);i++)
  {
    for(int j=0;j<n;j++)
    {
      if(!(i&(1<<j)))
      {
        for(int k=0;k<m;k++)
        {
          if(!(i==(1<<n)-1&&str[j]=='0')&&!(i==0&&str[j]=='0'))
            dp[i|(1<<j)][(k*10+str[j]-'0')%m]+=dp[i][k];
        }
      }
    }
  }
  long long int ans=dp[(1<<n)-1][0];
  for(int i=0;i<10;i++)
  {
    ans/=fact[cnt[i]];
  }
  cout<<ans<<endl;
  return 0;
}
