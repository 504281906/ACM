#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int T,n,m,i,j;
	int f[4000];
	scanf("%d",&T);
	while (T--)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		scanf("%d",&m);
		for (i=1;i<=m;i++)
		{
			int p;
			scanf("%d",&p);
			for (j=p;j<=n;j+=p)
			{
				int k=j % 7;
				if (k!=0 && k!=6) f[j]++;
			}
		}
		int s=0;
		for (i=1;i<=n;i++)
		if (f[i]) s++;
		printf("%d\n",s);
	}
	return 0;
}
