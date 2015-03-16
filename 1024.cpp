#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1000010];
int b[1000010],c[1000010];
long long max(int *a,int m,int n)
{
	long long k;
	memset(c,0,sizeof(c));
	b[0]=0;
	for (int i=1;i<=m;i++)
	{
		int j;
		k=-0x7fffffff;
		for (j=i;j<=n;j++)
		{
			if (b[j-1]<c[j-1])
				b[j]=c[j-1]+a[j-1];
			else
				b[j]=b[j-1]+a[j-1];
			c[j-1]=k;
			if (k<b[j])
				k=b[j];
		}
		c[j-1]=k;
	}
	return k;
}
int main()
{
	int m,n;
	while (~scanf("%d%d",&m,&n))
	{
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		long long s=max(a,m,n);
		printf("%lld\n",s);
	}
	return 0;
}
