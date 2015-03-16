#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int a[55],b[55],i,n;
	while (~scanf("%d",&n))
	{
		int k[3];
		memset(b,0,sizeof(b));
		memset(a,0,sizeof(a));
		int m=n*(n-1)/2-1;
		for (i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]++;
			a[y]++;
			b[x]++;
		}
		int t=1;
		for (i=n;i>0;i--)
		{
			if (a[i]!=n-1) k[t++]=i;
			if (t==3) break;
		}
		if (b[k[1]]>=b[k[2]])
		printf("%d %d\n",k[1],k[2]);
		else
		printf("%d %d\n",k[2],k[1]);
	}
	return 0;
}

