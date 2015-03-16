#include <stdio.h>
#include <string.h>
int main()
{
	long t,m,n,k;
	scanf("%ld",&t);
	while (t--)
	{
		scanf("%ld%ld",&m,&n);
		if (m==1) printf("NO\n");
		else 
		{
		   if ((n%2&&m%2)||(n%2==0&&m%2==0)) printf("YES\n");
		   else printf("NO\n");
		}
	}
	return 0;
}

