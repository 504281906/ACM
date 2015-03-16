#include <stdio.h>
int main()
{
	__int64 s;
	int max,i,t,n;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		 s=1;max=1;
		for (i=2;i<=n;i++)
		{
		s=(s+2);
		max=(max+s)%10000;
		}
		printf("%d\n",max);
	}
	return 0;
}
