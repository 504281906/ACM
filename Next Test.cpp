#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int a[3010],n,i;
	while (~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			a[k]=1;
		}
		for (i=1;i<=n+1;i++)
		{
			if (a[i]==0)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
