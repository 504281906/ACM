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
vector <int>vc[100010];
int ans[100010][5];
void dp(int u,int v)
{
	int k,i;
	for (i=0;i<vc[u].size();i++)
	{
		k=vc[u][i];
		if (k!=v)
		{
			dp(k,u);
			ans[u][1]+=ans[k][0];
			ans[u][0]+=(ans[k][0]>ans[k][1]?ans[k][0]:ans[k][1]);
		}
	}
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,i;
	while(~scanf("%d",&n))
	{
		for (i=1;i<=n;i++)
			vc[i].clear();
		memset(ans,0,sizeof(ans[0]));
		for(i=1;i<=n;i++)
			scanf("%d",&ans[i][1]);
		for (i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			vc[u].push_back(v);
			vc[v].push_back(u);
		}
		for (i=1;i<=n;i++)
		{
			if(vc[i].size()==1)
			{
				dp(i,-1);
				int max=ans[i][0]>ans[i][1]?ans[i][0]:ans[i][1];
				printf("%d\n",max);
				break;
			}
		}
	}
	return 0;
}
