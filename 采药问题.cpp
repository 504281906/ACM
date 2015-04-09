#include <stdio.h>    /*a:采此株药需要的时间    b：此药的价值   f[n]：n这个时间的最大价值。*/ 
#include <stdlib.h>
int main()
{
      int i,j,max=0,n,m;   
      int a[1000],b[1000],f[1000];
      scanf("%d%d",&n,&m);
      for (i=1;i<=m;i++)
       scanf("%d%d",&a[i],&b[i]);
       for (i=1;i<=m;i++)
           for (j=n;j>=a[i];j--)
           if ((j==a[i])||(f[j]<f[j-a[i]]+b[i])&&(f[j-a[i]]!=0)) f[j]=f[j-a[i]]+b[i];
      for (i=1;i<=n;i++)
      if (f[i]>max) max=f[i];
      printf("%d",max);
}
