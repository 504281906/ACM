#include <stdio.h>
int main()
{
	int a,b,a1,b1,f,k;
	while (scanf("%d%d%d",&a,&b,&k))
	{
		if (a==0&&b==0) return 0;
		a1=a;b1=b;f=1;
		while (k--)
		{
			if (a1%10!=b1%10) 
			{
		     	f=0;	
			    break;
		    } 
		    a1/=10;
		    b1/=10;
		}
		if (f==1) printf("-1\n");
		else printf("%d\n",a+b);
	}
	return 0;
}
