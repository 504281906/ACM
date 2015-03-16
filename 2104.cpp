#include<stdio.h>
int main()
{
	long n,m,t;
	while(scanf("%ld%ld",&n,&m)&&n!=-1&&m!=-1)
	{
		while (m!=0 && m!=1)
		{
			t=n%m;
			n=m;
			m=t;
		}
		if (m==1) printf("YES\n");
		else printf("POOR Haha\n");
	}
	return 0;
}
