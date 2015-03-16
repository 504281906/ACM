#include <stdio.h>
int main()
{
	int n,a,i,t,f=0;
	scanf("%d",&t);
	while (t--)
	{
		if (f)
		printf("\n");
		f=1;
		int s=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a);
			s+=a;
		}
		printf("%d\n",s);
	}
	return 0;
}
