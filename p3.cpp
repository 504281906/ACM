#include <stdio.h>
int main()
{
	int n,a,s,j,i,f,k;
	int b[100001];
 	while (scanf("%d",&n)!=EOF &&n)
 	{
		s=0;
		for (i=1;i<=n;i++)
		{

			scanf("%d",&a);
			s=s^a;
		}
		printf("%d\n",s);
	}
	return 0;
}
