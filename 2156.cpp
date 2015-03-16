#include <stdio.h>
int main()
{
	int i,n,j;
	double s,t;
	while(scanf("%d",&n)!=EOF && n)
	{
	  s=1.00;t=0.00;
	  for (i=2;i<=n;i++)
	  {
	 	t+=2.000/i;
		s=t+s+1;
	 }
		printf("%.2lf\n",s);		
	}
	return 0;	
}
