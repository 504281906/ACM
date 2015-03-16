#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int t=1;
	double a,b,c;
	while (~scanf("%lf%lf%lf",&a,&b,&c) && (a+b+c))
	{
		printf("Triangle #%d\n",t++);
		if (c==-1)
		{
			double s=sqrt(a*a+b*b);
			printf("c = %.3lf\n",s);
		}
		else 
		if (a==-1)
		{
			if (b>=c) printf("Impossible.\n");
			else
			{
				double s=sqrt(c*c-b*b);
				printf("a = %.3lf\n",s);
			}
		}
		else
		{
			if (a>=c) printf("Impossible.\n");
			else
			{
				double s=sqrt(c*c-a*a);
				printf("b = %.3lf\n",s);
			}
		}
		cout<<endl;
	}
	return 0;
}
