#include <stdio.h>
int main ()
{
    int n,m,a=0,b,i;
	while(scanf("%d%d",&n,&m))
	{
		if(n==1)printf("0\n");
		else
		{
		for(b=1,i=1;i<=m;i++)
		{
		    a=10*b/n;
			b=10*b%n;
		}
		printf("%d\n",a);
		}
	}
	return 0;
} 
