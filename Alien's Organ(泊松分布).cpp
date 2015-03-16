#include <stdio.h>
#include <math.h> 
int main()
{
	int t,i,n;
	double m;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%lf",&n,&m);
		double k=1.000;
		double s=exp(-m); 
		for (i=1;i<=n;i++)
		{
			k*=(i*1.000);
			s+=exp(-m)*pow(m,i)/k;
		}
		printf("%0.3lf\n",s);
	}
	return 0;
} 
