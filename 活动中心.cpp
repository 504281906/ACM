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
int T,cas,n;
double x[100010],y[100010];
double dis(double k)
{
	int i;
	double s=0;
	for (i=1;i<=n;i++)
		s+=sqrt(y[i]*y[i]+(x[i]-k)*(x[i]-k));
	return s;
}
int main()
{
	int i;
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		int min=0x3fffffff;
		int max=-0x3fffffff;
		for (i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x[i],&y[i]);
			if (min>x[i]) min=x[i];
			if (max<x[i]) max=x[i];
		}
		double l=min;
		double r=max;
		double a=dis(l);
		double b=dis(r);
		double mid=0;
		while (1)
		{
			double ss=mid;
			mid=(l+r) / 2;
			double s=dis(mid);
			if (s>a && s>b) 
			{
				mid=ss;
				break;
			}
			if (fabs(s-a)>fabs(s-b)) 
			{
				
				if (fabs(l-mid)<1e-15)
					break;
				a=s;
				l=mid;
			}
			else 
			{	
				if (fabs(r-mid)<1e-15)
					break;
				b=s;
				r=mid;
			}
		}
		printf("Case %d: %.6lf\n",cas,mid);
	}
	return 0;
}
