#include<stdio.h>
#include <string.h>
__int64 x[36];
int main()
{
	int i,j,n;
	x[0]=1;
	for(i=1;i<=35;i++)
	{
		x[i]=0;
		for(j=0;j<=i;j++)
			x[i]+=x[j]*x[i-j-1];
	}
	i=1;
	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		printf("%d %d %I64d\n",i++,n,x[n]*2);
	}
   return 0;
}
