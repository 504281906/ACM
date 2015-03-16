#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define N 510
struct node
{
	char a[5],b[5];
}c[N],d[N];
int eage[N][N],vis[N],isvis[N];
int c1,d1,n,m,v;
using namespace std;
int find(int k)
{
	int i,j;
	for (i=0;i<d1;i++)
		if (eage[k][i] && !isvis[i])
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
	int T,i,j;
	char a[5],b[5];
	scanf("%d",&T);
	while (T--)
	{
		c1=0;
		d1=0;
		scanf("%d%d%d",&n,&m,&v);
		for (i=0;i<v;i++)
		{
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
		int ans=0;
		memset(eage,0,sizeof(eage));
		for (i=0;i<c1;i++)
			for (j=0;j<d1;j++)
				if (strcmp(c[i].a,d[j].b)==0 || strcmp(c[i].b,d[j].a)==0)
					eage[i][j]=1;
		memset(vis,-1,sizeof(vis));
		for (i=0;i<c1;i++)
		{
			memset(isvis,0,sizeof(isvis));
			if (find(i))
				ans++;
		}
		printf("%d\n",v-ans);
	}
	return 0;
}
