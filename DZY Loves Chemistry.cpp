#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int f[55][55];
int n,m,i,j;
struct node
{
	int x,y;
}p[55];
int cmp(node a,node b)
{
	return a.y>b.y;
}
int main()
{
	while (scanf("%d%d",&n,&m)==2)
	{
		memset(f,0,sizeof(f));
		for (i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			f[a][0]++;
			f[a][f[a][0]]=b;
			f[b][0]++;
			f[b][f[b][0]]=a;
		}
		for (i=1;i<=n;i++)
		{
			p[i].x=i;
			p[i].y=f[i][0];
		}
		sort(p+1,p+n,cmp);
		map<int,int>mp;
		__int64 s=1;
		for (i=1;i<=n;i++)
		{
			int k=f[i][0];
			for (j=1;j<=f[i][0];j++)
				if (mp[f[i][j]]) k--;
			mp[i]=1;
			s=s*pow(2,k);
		}
		printf("%I64d\n",s);
	}
	return 0;
}
