#include <stdio.h>
int main()
{
	int i,t,n;
	long f[10001];
	scanf("%d",&t);
	f[1]=2;
	for (i=2;i<=10001;i++)
	 f[i]=f[i-1]+6*(i-1);
	while (t--)
	{
		scanf("%d",&n);
		printf("%ld\n",f[n]);
	}
	return 0;
}
