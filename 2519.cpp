#include <stdio.h>
int main()
{
	long t,i,m,n;
	double s;
	scanf("%ld",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		if (m>n) 
		{
			printf("0\n");
			continue;
		}
		s=1.000;
		for (i=1;i<=m;i++)
		  s*=(i+(n-m))/(double)i;
		printf("%.0lf\n",s);
	}
	return 0;
}
