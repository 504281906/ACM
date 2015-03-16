#include <stdio.h>
#include <string.h>
int main()
{
 	long a[10000],i,m,n,j;
 	double f[10000],b[10000],k;
 	while (scanf("%ld%ld",&m,&n))
 	{
	 	  if (m+n==0) break;
	 	 for(i=1;i<=n;i++)
			scanf("%ld%lf",&a[i],&b[i]);
		for(i=1;i<=n;i++)
			b[i]=1-b[i];
		for(i=0;i<10000;i++)
			f[i]=1;
         for(i=1;i<=n;i++)
			for(j=m;j>=a[i];j--)
				if(f[j]>f[j-a[i]]*b[i])
					f[j]=f[j-a[i]]*b[i];
          printf("%.1lf%%\n",(1-f[m])*100);
}
return 0;    
}
