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
#define eps 1e-8
using namespace std;
//(a2b3-a3b2,a3b1-a1b3,a1b2-a2b1)
struct point 
{
	double x,y,z;
	point(double x=0,double y=0,double z=0):x(x),y(y),z(z){} 
}a,b,c;
point operator - (point a,point b)
{
	return point(a.x-b.x,a.y-b.y,a.z-b.z);
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
double across(point a,point b)
{
	return 
}
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%lf%lf%lf",&a.x,&a.y,&a.z);
		scanf("%lf%lf%lf",&b.x,&b.y,&b.z);
		scanf("%lf%lf%lf",&c.x,&c.y,&c.z);
		double A=dis(a,b);
		double B=dis(b,c);
		double C=dis(a,c);
		double D=2*A*B;
		double ac=(A*A+B*B-C*C)/D;
		double sc=sqrt(1-ac*ac);
		double ans=0.5*A*B*sc;
		printf("%.6lf\n",ans);
	}
	return 0;
}
