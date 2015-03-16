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
double h,a,b,k;
int main()
{
	int cas=1;
	while (~scanf("%lf%lf%lf%lf",&h,&a,&b,&k) && (a+b+h+k))
	{
		printf("Case #%d: ",cas++);
		if (a-h>=EPS)
		{
			puts("YES");
			continue;
		}
		if (b-a>=EPS)
		{
			puts("NO");
			continue;
		}
		double c=(a-b)*1.0;
		if (c*1.0/h*(k-1)+a-h>=EPS) 
		{
			puts("YES");
			continue;
		}
		if (c*k-b>EPS) 
			puts("YES");
		else puts("NO");
	}
	return 0;
}
