#include <stdio.h>
#include <math.h>
int main()
{
	int l,i,k,j,f,n,z,y,min;
	int a[10001];
	k=1;
	for (i=2;i<=10000;i++)
	{
		f=1;
		for (j=2;j<=sqrt(i)+1;j++)
		 if (i%j==0) 
		 {
				f=0;
				break;
		 }
		 if (f) a[k++]=i;
	}
	while (scanf("%d",&n)!=EOF)
	{
		l=n/2;min=20000;
		for (i=1;a[i]<=l;i++)
		 for (j=i;a[j]<n;j++)
		  if (a[i]+a[j]==n && a[j]-a[i]<min)
		   {
				min=a[j]-a[i];
				z=i;
				y=j;
				break;
		   }
		printf("%d %d\n",a[z],a[y]);   
	}	 
	return 0;
}
