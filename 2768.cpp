#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 510
struct node
{
	char a[5],b[5];
}c[N],d[N];
int c1,d1,n,T;
int f[N][N],vis[N],isvis[N];
int find(int k)
{
	int i;
	for (i=0;i<d1;i++)
	if (f[k][i] && !isvis[i])
	{
		isvis[i]=1;
		if (vis[i]==-1 || find(vis[i]))
		{
			vis[i]=k;
			return true;
		}
	}
	return false;
}
int main()
{
	int i,j;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&c,&d,&n);
		c1=0,d1=0;
		for (i=0;i<n;i++)
		{
			char a[5],b[5];
			scanf("%s%s",&a,&b);
			if (a[0]=='C')
			{
				strcpy(c[c1].a,a);
				strcpy(c[c1].b,b);
				c1++;
			}
			else 
			{
				strcpy(d[d1].a,a);
				strcpy(d[d1].b,b);
				d1++;
			}
		}
		memset(f,0,sizeof(f));
		for (i=0;i<c1;i++)
			for (j=0;j<d1;j++)
				if (strcmp(c[i].a,d[j].b)==0 || strcmp(c[i].b,d[j].a)==0)
					f[i][j]=1;
		int ans=0;
		memset(vis,-1,sizeof(vis));
		for (i=0;i<c1;i++)
		{
			memset(isvis,0,sizeof(isvis));
			if (find(i))
				ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
