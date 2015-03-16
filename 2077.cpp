#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
__int64 a[25];
void ff()
{
	int i;
	a[0]=0;
	for (i=1;i<21;i++)
		a[i]=3*a[i-1]+1;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--)
	{
		ff();
		scanf("%d",&n);
		printf("%I64d\n",2*a[n-1]+2);
	}
	return 0;
}

