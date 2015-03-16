#include <stdio.h>
int main()
{
 	long i,j;
 	__int64 m,n,a[100];
 	while (scanf("%I64d%I64d",&m,&n) && (m+n))
	 {
	 	  for (i=0;i<=m;i++)
	 	   a[0,i]=1;
 	      for (i=0;i<=n;i++)
 	       a[i,0]=1;
          for (i=1;i<=m;i++)
           for (j=1;j<=n;j++)
            a[i,j]=a[i-1,j]+a[i,j-1];
          printf("%I64d\n",a[m,n]);
    }
    return 0;
}
