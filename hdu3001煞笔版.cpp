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
#define LL __int64
int dis[15][15];
int a[15],n,m,i,u,v,d;
#define min(a,b) a>b?b:a
int main()
{
	while (2==scanf("%d%d",&n,&m))
	{
		memset(dis,-1,sizeof(dis));
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&d);
			if (dis[u][v]==-1)
				dis[u][v]=dis[v][u]=d;
			else dis[u][v]=dis[v][u]=min(dis[u][v],d);
		}
		for (i=1;i<=n;i++)
			a[i-1]=i;
		int ans=0x7fffffff,k=0;
		do
		{
			int sum=0,f=0;
			for (i=1;i<n;i++)
				if (dis[a[i-1]][a[i]]==-1)
				{
					f=1;
					break;
				}
				else
					sum+=dis[a[i-1]][a[i]];
			if (f) continue;
			else if (sum<ans) 
			{
				k=1;
				ans=sum;
			}
		}while (next_permutation(a,a+n));
		if (k==0) ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}
