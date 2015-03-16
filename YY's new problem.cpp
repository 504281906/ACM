#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[10010];
int main()
{
	int T,n,i,j,k;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int f=0;
		for (i=1;i<n-1;i++)
		{
			for (j=i+1;j<n;j++)
			{
				int s=a[i]-a[j];
				for (k=j+1;k<=n;k++)
					if (a[j]-a[k]==s) 
					{
						f=1;
						break;
					}
				if (f) break;
			}
			if (f) break;
		}
		if (f) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
