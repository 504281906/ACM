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
using namespace std;
int main()
{
	double a[4];
	char b[4][5];
	int T,i,cas;
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		scanf("%lf%s%lf%s%lf%s",&a[1],&b[1],&a[2],&b[2],&a[3],&b[3]);
		for (i=1;i<=2;i++)
		{
			if (strcmp(b[i],"m")==0)
					{
						a[i]*=1000;
						
					}
			else if (strcmp(b[i],"dm")==0)
					{
						a[i]*=100;
					
					}
			else if (strcmp(b[i],"cm")==0)
					{
						a[i]*=10;
						
					}
			else if (strcmp(b[i],"um")==0)
					{
						a[i]/=1000;
						
					}
			else if (strcmp(b[i],"nm")==0)
					{
						a[i]/=1000000;
					
					}
		}
		double s=0;
		s=a[3]*a[1]/a[2];
		printf("Case %d: %.2lfpx\n",cas,s);
	} 
	return 0;
}
