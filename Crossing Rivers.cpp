#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int t=1,i,n,l,a,b,v;
	while (~scanf("%d%d",&n,&l) && n+l)
	{
		double s=l;
		for (i=0;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&v);
			s-=b;
			s+=2.0*b/v;
		}
		printf("Case %d: %.3lf\n\n",t++,s);
	}
	return 0;
}
