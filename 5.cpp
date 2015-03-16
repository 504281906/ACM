#include <stdio.h>
int main()
{
	int n,m,t,i;
	__int64 a[100],k=1;
	scanf("%I64d",&t);
	a[0]=0;a[1]=0;a[2]=1;
	 for(i=3;i<21;i++)
      a[i]=(i-1)*(a[i-1]+a[i-2]);
	while (t--)
	{ 
		scanf("%I64d%I64d",&n,&m);
		for (i=1;i<=m;i++)
	    	k*=(i+n-m)*1.00000/i;
	    k*=a[m];
	    printf("%I64d\n",k);
	    k=1;
	}
	return 0;
}
