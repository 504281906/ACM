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
#define GG 1000010
using namespace std;
int a[GG+10];
int main()
{
	int T,i,cas=1,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int max=0;
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			int s=10000-(100-k)*(100-k);
			a[s]++;
			if (max<a[s])
				max=a[s];
		}
		int flag=0;
		for (i=1;i<=GG;i++)
		{
			if (a[i]==max)
				flag++;
			else
			if (a[i] && a[i]!=max)
			{
				flag=-1;
				break;
			}
		}
		int ff=0;
		printf("Case #%d:\n",cas++);
		if (flag>1) printf("Bad Mushroom");
		else
		{
			for (i=1;i<=GG;i++)
			{
				if (a[i]==max)
				{
					printf(ff==0?"%d":" %d",i);
					ff++;
				}
			}
		}
		printf("\n");
	}
	return 0;
}

