#include<stdio.h>
int main()
{
  	int n,i,j,tem;
	while(~scanf("%d",&n))
	{
 		int a[n+5];
		for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		for(j=1;j<n;j++)
	{
		tem=a[0];
		for(i=0;i<j;i++)
		{
		if(a[i]>a[j])
		{
		tem=a[i];
		a[i]=a[j];
		a[j]=tem;
	}}}
		printf("%d",a[0]);
		for(i=1;i<n;i++)
		printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}
