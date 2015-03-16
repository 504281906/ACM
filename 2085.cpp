#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	__int64 a[35],b[35];
	int i,n;
	a[0]=1;b[0]=0;
	for (i=1;i<=33;i++)
	{
		a[i]=a[i-1]*3+b[i-1]*2;
		b[i]=a[i-1]+b[i-1];
	}
	while (~scanf("%d",&n) && n!=-1)
		printf("%I64d, %I64d\n",a[n],b[n]);
	return 0;
}
