#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#define LL __int64
#define EPS 1e-8
using namespace std;
LL h,a,b,k;
int main()
{
	int cas=1;
	while (~scanf("%I64d%I64d%I64d%I64d",&h,&a,&b,&k) && (a+b+h+k))
	{
		printf("Case #%d: ",cas++);
		if (a>=h)
		{
			puts("YES");
			continue;
		}
		if (b>=a)
		{
			puts("NO");
			continue;
		}
		LL c=a-b;
		if ((k-1)*c+a-h>=0)
		{
			puts("YES");
			continue;
		}
		if (c*k-b>0)
			puts("YES");
		else 
			puts("NO");
	}
	return 0;
}
