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
//#define DEBUG
int f[2510][2510],vis[2510][2510],d[2510];
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int T,n,m,s,a,b,c,i;
	while (~scanf("%d%d%d%d",&T,&n,&m,&s))
	{
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		for (i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			vis[a][b]=vis[b][a]=1;
			f[a][b]=f[b][a]=c;
		}
		for (i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			vis[a][b]=1;
			f[a][b]=c;
		}
		int t=T-1;
		while (t--)
		{
			int max=10010;
			int pos=0;
			for (i=1;i<=T;i++)
				if (vis[s][i] && max>f[s][i])
				{
					max=f[s][i];
					pos=i;
				}
			//if (pos==0) break;
			d[pos]=1;
			vis[s][pos]=0;
			for (i=1;i<=T;i++)
				if (vis[pos][i]==1)
				{
					if (vis[s][i]=0)
					{
						f[s][i]=max+f[pos][i];
						vis[s][i]=1;
					}
					else
						f[s][i]=min(f[s][i],max+f[pos][i]);
				}
		}
		for (i=1;i<=T;i++)
			if (i==s) printf("0\n");
			else
			if (d[i]==0)
				printf("NO PATH\n");
			else printf("%d\n",f[s][i]);
	}
	return 0;
}
