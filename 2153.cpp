#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n;
	int a[111][111];
	while (scanf("%d",&n)!=EOF && n)
	{
		j=1;memset(a,0,sizeof(a));
		for (i=1;i<=n;i++,j++)
		 a[1][i]=j;
		for (i=2;i<=n;i++,j++)
		 a[i][n]=j;
		for (i=n-1;i>=1;i--,j++)
		 a[n][i]=j;
		for (i=n-1;i>=2;i--,j++)
		 a[i][1]=j;
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			if (a[i][j]!=0)
			printf("%3d",a[i][j]);
			else printf("   ");
			printf("\n");
		}
	}
	return 0;
}
