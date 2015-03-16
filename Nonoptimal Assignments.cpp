#include <cstdio>
#include <iostream>
using namespace std;
int a[110][110];
int main()
{
	int n,i,j;
	while (~scanf("%d",&n))
	{
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				a[i][j]=100;
		a[1][1]=0;
		a[1][2]=1;
		a[2][1]=1;
		a[2][2]=10;
		for (i=1;i<=n;i++)
		{
			printf("%d",a[i][1]);
			for (j=2;j<=n;j++)
				printf(" %d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}
