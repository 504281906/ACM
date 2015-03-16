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
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
int a[110],c1[10010],c2[10010],f[10010],n,m,i,j,k;
int main()
{
	while (~scanf("%d",&n))
	{
		m=0;
		memset(c1,0,sizeof(c1));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			m+=a[i];
		}
		sort(a+1,a+1+n);
		memset(c2,0,sizeof(c2));
		c1[0]=1;c1[a[1]]=1;
		for (i=2;i<=n;i++)
		{
			for (j=0;j<=m;j++)
				if (c1[j])
				{
					for (k=0;k+j<=m && k<=a[i];k+=a[i])
					{
						if (j<=k)
							c2[k-j]+=c1[j];
						else
							c2[j-k]+=c1[j];
						c2[j+k]+=c1[j];
					}
				}
			for (j=0;j<=m;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		int t=0;
		for (j=1;j<=m;j++)
			if (c1[j]==0)
				f[t++]=j;
		if (t==0) printf("%d\n",t);
		else
		{
			printf("%d\n",t);
		for (i=0;i<t-1;i++)
			printf("%d ",f[i]);
		cout<<f[t-1]<<endl;
		}
	}
	return 0;
}
