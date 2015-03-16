#include <stdio.h>
int main()
{
	int i,j,n,a[10009]={0,0};
	for(i=2;i<=5000;i++)
	{
		for(j=2;j*i<=10000;j++)
		{
			if(a[j*i]==1) continue;
			 a[j*i]=1;
		}
	}
	a[0]=1;a[1]=1;
	while(scanf("%d",&n)!=EOF)
	{
		int t=0;
		if(n==0) break;
		for(i=0;i<=n/2;i++)
			if(a[i]==0&&a[n-i]==0&&n!=2*i) t++;
		printf("%d\n",t);
	}
	return 0;
}
