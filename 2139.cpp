#include <stdio.h>
int main()
{
	int n,i,s;
	while(scanf("%I64d",&n)!=EOF&&n)
	{
	   s=n*(n+1)*(n+2)/6;
	   printf("%I64d\n",s);
	}
	return 0;
}
