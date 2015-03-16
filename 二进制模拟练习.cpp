#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,i,j,a[10010];
	while (~scanf("%d",&n))
	{
		int m=1<<(n);
		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
				if (i & (1<<j))
					a[j]=1;
				else a[j]=0;
			for (j=n-1;j>=0;j--)
				printf("%d",a[j]);
			cout<<endl; 
		}
	}
	return 0;
}
