#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int d[30010],ans[30010];
vector<int>vt[30010];
priority_queue<int>q;
int main()
{
	int T,n,m,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
			vt[i].clear();
		for (i=1;i<=m;i++)
		{
			int v,u;
			scanf("%d%d",&u,&v);
			d[u]++;
			vt[v].push_back(u);
		}
		for (i=1;i<=n;i++)
			if (!d[i]) q.push(i);
		int t=0;
		while (!q.empty())
		{
			int u=q.top();
			q.pop();
			ans[t++]=u;
			int size=vt[u].size();
			for (i=0;i<size;i++)
			{
				int v=vt[u][i];
				d[v]--;
				if (d[v]==0)
					q.push(v);
			}
		}
		for (i=t-1;i>0;i--)
			printf("%d ",ans[i]);
		printf("%d\n",ans[0]);
	}
	return 0;
}
