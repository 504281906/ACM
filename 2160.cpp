#include <stdio.h>
int main()
{
	int i,t,n;
	int a[21];
	scanf("%d",&t);
	a[1]=1;a[2]=2;
	for (i=3;i<=20;i++)
	 a[i]=a[i-1]+a[i-2];
	while (t--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}
