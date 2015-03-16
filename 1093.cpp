#include <stdio.h>
int main()
{
	int n,m,num,sum,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=0;
		scanf("%d",&m);
		for(j=1;j<=m;j++)
		{
			scanf("%d",&num);
			sum += num;
		}
		printf("%d\n",sum);
	}
	return 0;
}
