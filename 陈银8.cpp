#include<stdio.h>
int main()
{
	int n,i,j,x=0;
	int a[105];
	while(~scanf("%d",&n)&&n)
	{
		x=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		{
			while(a[i]>=100)
			{
				x=a[i]/100;
				a[i]=a[i]%100;
			}
			while(a[i]>=50)
			{
				x=x+a[i]/50;
				a[i]=a[i]%50;}
			while(a[i]>=10)
			{
				x=x+a[i]/10;
				a[i]=a[i]%10;}
			while(a[i]>=5)
			{
				x=x+a[i]/5;
				a[i]=a[i]%5;
			}
			while(a[i]>=2)
			{
				x=x+a[i]/2;
				a[i]=a[i]%2;
			}
			x=x+a[i];
		}
		printf("%d\n",x);
	}
	return 0;
}
