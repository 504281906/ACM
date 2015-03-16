#include <stdio.h>
#include <math.h>

int main()
{
	__int64 a,s;
	double b,i;
	int n;
	while (scanf("%d",&n)!=EOF)
	{
	   s=0;
       while (n--)
       {
			scanf("%I64d",&a);
			getchar();
			scanf("%lf",&b);
			getchar();
			i=0;
			while(a>0)
			{
				s+=a%10*pow(b,i);
				a=a/10;	
				i++;					
			}
	   }
	   printf("%I64d\n",s);
	}
	return 0;
}
