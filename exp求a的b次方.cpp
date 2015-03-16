#include <cmath>
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
	int a,b;
	while (~scanf("%d%d",&a,&b))
	{
		double s=log(a);
		s=exp(b*s);
		printf("%.0lf\n",s);
	}
	return 0;
}
