#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
bool cmp(double a,double b)
{
	return a>b;
}
bool cmp1(double a,double b)
{
	return b>a;
}
double x[1000],y[1000];
int main()
{
	int T,n,i,t=0;
	freopen("A-small-practice.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		printf("Case #%d: ",++t);
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%lf",&x[i]);
		for (i=0;i<n;i++)
			scanf("%lf",&y[i]);
		sort(x,x+n,cmp);
		sort(y,y+n,cmp1);
		double s=0;
		for (i=0;i<n;i++)
			s+=x[i]*y[i];
		printf("%.0lf\n",s);
	}
	return 0;
} 
