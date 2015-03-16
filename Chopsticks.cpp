#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[5010];
int f[5010];
int vis[5010];
long long ff(int a,int b)
{
	return (a-b)*(a-b);
}
int main()
{
	int T,i,k,n,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&k,&n);
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		k+=8;
		long long s=0;
		int t=0;
		memset(vis,0,sizeof(vis));
		while (k)
		{
			for (i=0;i<n-1;i++)
			{
				if (vis[i]==0)
				for (j=i+1;j<n-1;j++)
				{
					if (a[j]-a[i]>t) break;
					if (a[j]-a[i]==t && vis[j]==0 && n-(j+1)-f[i]>0)
					{
						s+=ff(a[i],a[j]);
						k--;
						for (int h=0;h<=i;h++)
							f[h]+=3;
						for (int h=i;h<=j;h++)
							f[h]+=2;
						printf("%d %d\n",a[i],a[j]);
					}
				}
			}
			t++;
		}
		printf("%lld\n",s);
	}
	return 0;
}
