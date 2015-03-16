#include <stdio.h>
#include <string.h>
int main()
{
	long t,n,i,s;
	int a[100];
	scanf("%ld",&t);
	while (t--)
	{
		scanf("%ld",&n);
		memset(a,0,sizeof(a));
		a[0]=n%10;i=0;s=n;
		while (a[0]!=s||i==0)
		{
			i++;
			s=s*n%10;
			a[i]=s;
		}
		printf("%d\n",a[(n-1)%i]);
	}
	return 0;
}
