#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,i,j,a[1010];
	while (~scanf("%d",&n))
	{
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=1;i<n;i++)
		{
			for (j=i+1;j<=n;j++)
				if (a[i]<a[j])
				{
					a[i]=a[j];
					break;
				}
			if (j==n+1) a[i]=0;
		}
		a[n]=0;
		for (i=1;i<=n;i++)
			printf("%d\n",a[i]);
		//printf("\n");
	}
	return 0;
}
