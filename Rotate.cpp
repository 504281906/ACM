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
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
#define pi acos(-1)
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		double xx=0.0,yy=0.0;
		double x,y,p;
		double s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&x,&y,&p);
			double x1=xx;
			xx=(xx-x)*cos(p)-(yy-y)*sin(p)+x;
			yy=(yy-y)*cos(p)+(x1-x)*sin(p)+y;
			s=s+p;
	
		}
		double a=(1-cos(s))*(1-cos(s))+sin(s)*sin(s);
		double b=xx*(1-cos(s))-yy*sin(s);
		double c=yy*(1-cos(s))+xx*sin(s);
		xx=b/a;
		yy=c/a;
		s=s-floor(s/pi/2)*pi*2;
		printf("%.10lf %.10lf %.10lf\n",xx,yy,s);
	}
	return 0;
}
