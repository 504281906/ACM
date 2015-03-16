#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long t;
int n;
long long ff(int x)
{
	int i;
	t++;
	if (x==1) return 1;
	for (i=1;i<=x/2;i++)
		ff(i);
	return 1;
}
int main()
{
	while (~scanf("%d",&n))
	{
		t=0;
		/*if (n==0 || n==1 || n==2)
		{
			printf("1\n");
			continue;
		}*/
		ff(n);
		printf("%lld\n",t);
	}
	return 0;
}
