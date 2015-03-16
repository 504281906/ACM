#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",(n*n*n-1)*n*n*n/2-3*n*n*(n-1));
	}
	return 0;
}
