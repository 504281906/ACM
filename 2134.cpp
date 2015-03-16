#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	double s,r1,r2,p;
	p=3.1415926;
	while (scanf("%d",&n)!=EOF &&n)
	{
		s=p*n*n/3;
		r1=sqrt(s/p);
		r2=sqrt(s*2/p);
	    printf("%.3lf %.3lf\n",r1,r2);
	}
	return 0;
}
