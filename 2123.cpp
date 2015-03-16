#include <stdio.h>
int main()
{
	int t,n,i,j,f[10][10];
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		 for (j=1;j<=n;j++)
		  f[i][j]=i*j;
		for (i=1;i<=n;i++)
		{
		 for (j=1;j<=n;j++)
		  if (j==1) printf("%d",f[i][j]);
		  else printf(" %d",f[i][j]);
		  printf("%\n");
		}
	}
	return 0;
}
