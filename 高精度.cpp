#include<stdio.h>
long a[8000][800];
int main()
{
	long n,i,j,k;
	a[1][0]=1;
	a[2][0]=1;
	a[3][0]=1;
	a[4][0]=1;
	k=0;
	for(i=5;i<8000;i++)
		for(j=0;j<800;j++)
		{
			k+=a[i-1][j]+a[i-2][j]+a[i-3][j]+a[i-4][j];
			a[i][j]=k%10000;
			k/=10000;
		}
	while(k)
	{
		a[i][j++]=k%10000;
		k/=10000;
	}
	while(scanf("%ld",&n)>0)
	{
		for(i=799;i>=0;i--)
			if(a[n][i]!=0)
				break;
		printf("%ld",a[n][i]);
		for(i--;i>=0;i--)
			printf("%4.4ld",a[n][i]);
		printf("\n");
	}
	return 0;
}
