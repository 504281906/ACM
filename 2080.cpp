#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define pi 3.1415926
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		double x1,x2,y1,y2,a,b,c,f;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		a=sqrt(x1*x1+y1*y1);
		b=sqrt(x2*x2+y2*y2);
		c=sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) );
		f=(a*a+b*b-c*c)/(2*a*b);
	//	printf("%lf\n",f);
		f=acos(f)*180/pi;
		printf("%.2lf\n",f);
	}
	return 0;
}

