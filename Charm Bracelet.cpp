#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long f[15000];
int w[3500],d[3500];
int main()
{
	int n,m,i,j;
	long long max;
	while (~scanf("%d%d",&n,&m))
	{
		max=0;
		memset(f,0,sizeof(f));
		for (i=1;i<=n;i++)
			scanf("%d%d",&w[i],&d[i]);
		for (i=1;i<=n;i++)
			for (j=m;j>=w[i];j--)
				if ((f[j-w[i]]!=0 || j-w[i]==0 )&& f[j]<f[j-w[i]]+d[i])
					f[j]=f[j-w[i]]+d[i];
		for (j=1;j<=m;j++)
		if (max<f[j]) max=f[j];
		printf("%lld\n",max);
	}
	return 0;
}
