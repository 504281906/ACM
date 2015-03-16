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
int a[1010],b[1030],sta[2050];
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
		memset(sta,0,sizeof(sta));
		sta[0]=0;
		int t=0;
		for (i=1;i<=n;i++)
		{
			int t2=t;
			int t1=0;
			for (j=0;j<=t2;j++)
			{
				int k=sta[j] ^ a[i];
				sta[++t]=k;
				memset(b,0,sizeof(b));
				for (i1=i+1;i1<=n;i1++)
				{
					for (j1=0;j1<=1024;j1++)
					{
						if (b[j1]) b[j1&a[i1]++;
						if (j1==a[i1]) b[j1]++;
					}
				}
				if (b[k])
				{
					//printf("%d %I64d %I64d\n",i,sta[k],b[k]);
					ans=ans+b[k] % M;
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
