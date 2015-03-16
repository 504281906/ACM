#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	__int64 a,b,c;
	while (~scanf("%d",&n))
	{
		for (int i=0;i<n;i++)
		{
			scanf("%I64d%I64d%I64d",&a,&b,&c);
		if (a>b-c)
			puts("do not advertise");
		else if (a==b-c)
			puts("does not matter");
		else puts("advertise");
		}
	}
	return 0;
}

