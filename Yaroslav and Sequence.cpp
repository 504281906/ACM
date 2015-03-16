#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int n,m,t,i,k,s,max;
	while (~scanf("%d",&n))
	{
		t=0;
		s=0;
		m=2*n-1;
		max=0x7fffffff;
		for (i=0;i<m;i++)
		{
			scanf("%d",&k);
			if (k<0) t++;
			s+=fabs(k);
			if (max>fabs(k)) max=fabs(k);
		}
		if ((n % 2==1) || (t % 2==0) || (t>=n && (t-n) % 2==0)) printf("%d\n",s);
		else printf("%d\n",s-2*max);
	}
	return 0;
}
