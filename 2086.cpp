#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double a[3100];
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		scanf("%lf%lf",&a[0],&a[n+1]);
		double s=0,t=0;
		for (i=1;i<=n;i++)
		{
			double c;
			scanf("%lf",&c);
			t+=c;
			s+=2*t;
		}
		//printf("%lf\n",s);
		a[1]=(n*a[0]+a[n+1]-s)/(n+1);
		printf("%.2lf\n",a[1]);
	}
	return 0;
}

