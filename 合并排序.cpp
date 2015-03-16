#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define M 0x7fffffff
using namespace std;
int main()
{
	int a[100],b[100],c[100],n,m,i;
	while (~scanf("%d%d",&n,&m))
	{
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (i=0;i<m;i++)
			scanf("%d",&b[i]);
		sort(a,a+n);
		sort(b,b+m);
		a[n]=M;
		b[m]=M;
		int l=n+m;
		int k1=0,k2=0;
		for (i=0;i<l;i++)
		{
			if (a[k1]<=b[k2])
				c[i]=a[k1++];
			else 
				c[i]=b[k2++];
		}
		for (i=0;i<l;i++)
			printf("%d ",c[i]);
	}
	return 0;
}
