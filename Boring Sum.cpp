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
#define LL __int64
#define EPS 1e-8
using namespace std;
int a[100010],s[100010],g[100010];
int main()
{
	int n,i,j;
	while(~scanf("%d",&n) && n)
	{
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (i==1)
			{
				s[i]=a[1];
				continue;
			}
			int flag=0;
			for (j=i-1;j>=1;j--)
			{
				if (a[j] % a[i]==0 && !flag)
				{
					flag=1;
					s[i]=a[j];
				}
				if (!flag) s[i]=a[i];
				if (a[i] % a[j]==0 && !g[j])
					g[j]=a[i];
				if (g[j] && flag) break;
			}
		}
		LL ans=0;
		for (i=1;i<=n;i++)
		{
			if (g[i]==0) g[i]=a[i];
			ans+=s[i]*g[i];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
