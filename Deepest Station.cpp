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
#define LL __int64
#define EPS 1e-8
using namespace std;
double gg(double a,double b)
{
	return sqrt(a*a+b*b);
}
int main()
{
	double x,y,d;
	while (~scanf("%lf %lf %lf",&x,&y,&d))
	{
		double k=gg(x,y);
		if (k-d>0) puts("Impossible");
		else if (fabs(k-d)<=EPS) puts("Single staircase");
		else
		{
			double s=d-k;
			double h=sqrt(s*s*1.0/2);
			h=sqrt(h*h*1.0/2);
			//if (k+h==d-h) cout<<"YES"<<endl;
			double z=d-h;
			double bb=z*1.0/k;
			x=x*bb;
			y=y*bb;
			printf("%.10lf %.10lf %.10lf\n",x,y,h);
		}
	}
	return 0;
}
