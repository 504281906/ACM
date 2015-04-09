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
#define EPS 1e-8
using namespace std;
int a,b,c[1100],d[1100];
int f[1100],g[1100];
int main()
{
	int p,q,l,r,i,j,ans=0;
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	scanf("%d%d%d%d",&p,&q,&l,&r);
	for (i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);
		for (j=a;j<=b;j++)
			f[j]=1;
	}
	for (i=0;i<=1000;i++)
		g[i]+=g[i-1]+f[i];
	for (i=1;i<=q;i++)
	{
		scanf("%d%d",&c[i],&d[i]);
	}
	for (i=l;i<=r;i++)
	{
		for (j=1;j<=q;j++)
		{
			int x=c[j]+i;
			int y=d[j]+i;
			if (y>1000) y=1000;
			int flag=0;
			for (int k=x;k<=y;k++)
			{	
				if (f[k])
				{
					flag=1;
					ans++;
					break;
				}
		
			}	if (flag==1) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
