#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int T,t,x,y;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&x);
		y=x+1;
		int t=0;
		while (x || y)
		{
			if (x % 2 != y % 2) t++;
			x/=2;
			y/=2;
		}
		printf("%d\n",t);
	}
	return 0;
}
