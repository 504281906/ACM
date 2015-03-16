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
int f[100010];
int main()
{
	int n,m,x,y,i,k;
	while (~scanf("%d%d",&n,&m))
	{
		map<int,int>mp;
		int ff=0;
		for (i=1;i<=n;i++)
		{
			mp[i]=i;
			f[i]=i;
		}
		while (m--)
		{
			scanf("%d",&k);
			if (k==4)
			{
				ff=(ff+1)%2;
				continue;
			}
			if (k==3)
			{
				scanf("%d%d",&x,&y);
				int xx=mp[x];
				int yy=mp[y];
				mp[x]=yy;
				mp[y]=xx;
				int t=f[xx];
				f[xx]=f[yy];
				f[yy]=t;
				continue;
			}
			if ((k==1 && ff==0) || (k==2 && ff==1)) //x×ó±ß 
			{
				scanf("%d%d",&x,&y);
				int xx=mp[x];
				int yy=mp[y]-1;
				mp[x]=yy;
				mp[f[yy]]=xx;
				int t=f[xx];
				f[xx]=f[yy];
				f[yy]=t;
			}
			else //xÓÒ±ß 
			{
				scanf("%d%d",&x,&y);
				int xx=mp[x];
				int yy=mp[y]+1;
				mp[x]=yy;
				mp[f[yy]]=xx;
				int t=f[xx];
				f[xx]=f[yy];
				f[yy]=t;
			}
			for (i=1;i<=n;i++)
			cout<<f[i];
		cout<<endl;
		}
		/*for (i=1;i<=n;i++)
			cout<<f[i];
		cout<<endl;
		/*for (i=1;i<=n;i++)
			cout<<mp[i];*/
		LL ans=0;
		for (i=1;i<=n;i++)
			if (i % 2==1)
				ans+=f[i];
		cout<<ans<<endl;
	}
	return 0;
}
