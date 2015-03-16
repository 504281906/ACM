#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#define Pi acos(-1)
using namespace std;
int main()
{
	double a;
	while (~scanf("%lf",&a))
	{
		double s=0,x,y,z;
		s=sqrt(3.0)*a*a/4.0+Pi*a*a/6.0;
		z=4*(a*a-s);
		y=4*(a*a-Pi*a*a/4-z/2);
		x=a*a-z-y;
		printf("%.3lf %.3lf %.3lf\n",x,y,z);
	}
	return 0;
}
