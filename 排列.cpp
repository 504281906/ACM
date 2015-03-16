#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int a[1030],k,T,i,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		while (k--)
			next_permutation(a,a+n);
		for (i=0;i<n;i++)
			printf(i==0?"%d":" %d",a[i]);
		printf("\n");
	}
	return 0;
}

