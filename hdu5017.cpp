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
#define INF 100000
using namespace std;
double a,b,c,d,e,f;
double get(double A,double B,double C)
{
	if (B*B-4*A*C<EPS) return INF;
	else return (sqrt(B*B-4*C*A)-B)/(2*A);
}
double findc(double x,double y)
{
	double z=get(c,d*y+e*x,a*x*x+b*y*y+f*x*y-1);
	return x*x+y*y+z*z;
}
double find(double x)
{
	double l=-INF,r=INF;
	for (int i=0;i<200;i++)
	{
		double ll=l+(r-l)/3;
		double rr=r-(r-l)/3;
		if (findc(x,ll)>findc(x,rr))
			l=ll;
		else r=rr;
	}
	return findc(x,l);
}
double solve(double l,double r)
{
	for (int i=0;i<200;i++)
	{
		double ll=l+(r-l)/3;
		double rr=r-(r-l)/3;
		if (find(ll)>find(rr))
			l=ll;
		else r=rr;
	}
	return sqrt(find(l));
}
int main()
{
	while (~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f))
	{
		printf("%.7lf\n",solve(-INF,INF));
	}
	return 0;
}
