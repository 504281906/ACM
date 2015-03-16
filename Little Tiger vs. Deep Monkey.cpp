#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
double p,c[400010];	
int f[400010],a[400010],b[400010],h[400010];
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%lf",&n,&p);
		memset(f,0,sizeof(f));
		long long k=0;
		f[0]=1;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			k+=a[i];
		}
		for (i=1;i<=n;i++)
			for (j=k;j>=a[i];j--)
				if (f[j-a[i]])
					f[j]+=f[j-a[i]];
		k=1;
		for (i=1;i<=n;i++)
			k*=2;
		k=ceil(p*k);
		long long ans=0;
		for (i=0;i<=40000;i++)
		{
			ans+=f[i];
			if (ans>=k)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
