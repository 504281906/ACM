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
		double x1=0.0,y1=0.0;
		double x,y,p,xx,yy;
		double s=0;
		for (i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf",&x,&y,&p);
			xx,yy;
			xx=(x1-x)*cos(p)-(y1-y)*sin(p)+x;
			yy=(y1-y)*cos(p)+(x1-x)*sin(p)+y;
			x1=xx;y1=yy;
			/*xx=(x2-x)*cos(p)-(y2-y)*sin(p)+x;
			yy=(y2-y)*cos(p)+(x2-x)*sin(p)+y;
			x2=xx;y2=yy;*/ 
			s=s+p;
			if (s>2*pi) s-=2*pi;
		}
		double a=-x1*cos(s)+y1*sin(s)+x1;
		double b=-(2*cos(s)-cos(s)*cos(s)-1-sin(s)*sin(s));
		xx=a/b;
		
		printf("%.10lf %.10lf %.10lf\n",xx,yy,s);
	}
	return 0;
}
