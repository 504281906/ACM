#include<stdio.h>
int main()
{
	int i,n;
	double a[51]={0,1,2};
    for(i=3;i<51;i++)
     a[i]=a[i-1]+a[i-2];
	while(scanf("%d",&n)!=EOF)
	{
	   printf("%.0lf\n",a[n]);
	}
    return 0;
}
