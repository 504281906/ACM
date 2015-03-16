#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long f[10010],k[10010];
int main()
{
	int i,a,n,m,x;
	f[0]=0;k[0]=0;
	f[1]=1;f[2]=1;
	k[1]=1;k[2]=2;
	for (i=3;i<=10000;i++) 
	{
		f[i]=f[i-1]+f[i-2];
		k[i]=k[i-1]+f[i];
	}
	while (~scanf("%d%d%d%d",&a,&n,&m,&x))
	{
		if (x==1 || x==2)
		{
			printf("%d\n",a);
			continue;
		}
		long long s=0;
		s=(m-2*a-k[n-5]*a)/k[n-4];
		printf("%lld\n",2*a+k[x-3]*s+k[x-4]*a);
	}
	return 0;
}
