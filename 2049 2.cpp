#include <stdio.h>
int main()
{
	double s;
	int n,m,t,i;
	scanf("%d",&t);
	while (t--)
	{
		s=1;
		scanf("%d%d",&n,&m);
		for (i=1;i<=m;i++)
	    	s*=(i+n-m)/i;
	    printf("%.0lf\n",s);
	}
	return 0;
}
