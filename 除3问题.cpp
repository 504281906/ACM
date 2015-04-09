#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int T,i,a,b;
	scanf("%d",&T);
	int cc=1;
	while (T--)
	{
		int s=0,t=0;
		scanf("%d%d",&a,&b);
		if (a % 3!=1) t=1;
		if (b>a)
			t+=(b-a)/3*2;
		int k=(b-a)%3;
		for (i=0;i<k;i++)
			if ((b-i) % 3!=1) t++;
		printf("Case %d: %d\n",cc++,t);
	}
	return 0;
}
