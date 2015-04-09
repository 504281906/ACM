#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int a[35][35],i,j,n;
	memset(a,0,sizeof(a));
	a[1][1]=1;
	a[2][1]=1;a[2][2]=1;
	for (i=3;i<=30;i++)
		for (j=1;j<=i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	while (~scanf("%d",&n))
	{
		for (j=1;j<=n;j++)	
		{
			printf("1");
			for (i=2;i<=j;i++)
				printf(" %d",a[j][i]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

