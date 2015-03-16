#include <stdio.h>
int main()
{
	int n,i,j,k,a[1000];
	while (scanf("%d",&n) && n!=0)
	{
		for (i=1;i<=n;i++)
		 scanf("%d",&a[i]);
		scanf("%d",&k);
		j=0;
		for (i=1;i<=n;i++)
		 if (k==a[i]) j++;
		 printf("%d\n",j);
	}
	return 0;
}
