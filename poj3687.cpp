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
int a[210],d[210],T,n,m,u,v,i;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		vector<int>vt[210];
		priority_queue<int>q;
		memset(d,0,sizeof(d));
		scanf("%d%d",&n,&m);
		for (i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			d[u]++;
			vt[v].push_back(u);
		}
		for (i=1;i<=n;i++)
			if (!d[i]) q.push(i);
		int t=0;
		while(!q.empty())
		{
			u=q.top();
			a[++t]=u;
			q.pop();
			for (i=0;i<vt[u].size();i++)
			{
				v=vt[u][i];
				d[v]--;
				if (!d[v])
					q.push(v);
			}
		}
		if (t!=n) puts("-1");
		else
		{
			int b[210];
			for (i=1;i<=n;i++)
				b[a[i]]=n-i+1;
			for (i=1;i<=n;i++)
				printf(i==1?"%d":" %d",b[i]);
			cout<<endl;
		}
	}
	return 0;
}

