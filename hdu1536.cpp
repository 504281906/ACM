#include<bits/stdc++.h>
using namespace std;
int k,sg[10010],a[110],s[110],h[110],ans[110];
int mex(int x)
{
	if (sg[x]!=-1) return sg[x];
	bool vis[110];
	memset(vis,0,sizeof(vis));
	for (int i=0;i<k;i++)
	{
		int t=x-s[i];
		if (t<0) break;
		sg[t]=mex(t);
		vis[sg[t]]=true;
	}
	for (int i=0;;i++)
	if (vis[i]==0)
	{
		sg[x]=i;
		break;
	}
	return sg[x];
}
int main()
{
	int i,j,n,m;
	while (~scanf("%d",&k) && k)
	{
		for (i=0;i<k;i++)
			scanf("%d",&s[i]);
		sort(s,s+k);
		memset(sg,-1,sizeof(sg));
		sg[0]=0;
		memset(ans,0,sizeof(ans));
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for (j=1;j<=m;j++)
			{
				scanf("%d",&h[j]);
				ans[i]^=mex(h[j]);
			}
		}
		for (i=1;i<=n;i++)
			if (ans[i]==0) printf("L");
			else printf("W");
		cout<<endl;
	}
	return 0;
}
