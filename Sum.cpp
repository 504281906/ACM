#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int M=1e9+7;
long long num[20][10010];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	num[1][1]=1;
	for (i=2;i<=9;i++)
		num[i][1]=i;
	for (i=1;i<=9;i++)
		for (j=2;j<=n;j++)
		num[i][j]=(num[i][j-1]*10+i) % M;
	long long ans=0;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
		{
			scanf("%1d",&k);
			ans=(ans+(num[k][n-i+1]*i)%M+(num[k][n-j+1]*j)%M)%M;
		}
	printf("%lld\n",ans);
	return 0;
}
