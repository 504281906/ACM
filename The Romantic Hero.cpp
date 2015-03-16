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
const LL M=1e9+7;
int a[3000],b[3000],sta[3000];
int main()
{
	int T,i,i1,j,j1,n;
	scanf("%d",&T);
	while (T--)
	{
		LL ans=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(sta,0,sizeof(sta));sta[0]=1;
		for (i=1;i<=n;i++)
		{
			int vis[a[i]*2+1];
			memset(vis,0,sizeof(vis));
			for (j=0;j<=a[i]*2;j++)
			{
				if (sta[j]==0 || vis[j]) continue;
				int k=j ^ a[i];
				sta[k]+=1;
				vis[k]=1;
				memset(b,0,sizeof(b));
				for (i1=i+1;i1<=n;i1++)
				{
					for (j1=0;j1<=a[i1];j1++)
					{
						if (b[j1]) b[j1&a[i1]]++;
						if (j1==a[i1]) b[j1]++;
					}
				}
				if (b[k])
				{
					printf("%d %I64d %I64d\n",i,sta[k],b[k]);
					ans=ans+((sta[k]-1)+b[k]) % M;
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
