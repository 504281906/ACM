#include <stdio.h>
#include <math.h>
int main()
{
	double result;
	double x = 4.0;
	result = exp(x);
	printf("%lf (e ^ %d) = %lf\n",x,(int)x,result);
	return 0;
}

