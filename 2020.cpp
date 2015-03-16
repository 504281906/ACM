#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int n,i,j,t;
    int a[101],b[101],c[101];
    while (scanf("%d",&n) && n!=0)
    {   
          for (i=1;i<=n;i++)
          {
              scanf("%d",&a[i]);
              b[i]=abs(a[i]);
              c[i]=i;
          }
          for (i=1;i<n;i++)
           for (j=i+1;j<=n;j++)
               if (b[i]<b[j]) {t=c[i];c[i]=c[j];c[j]=t;
                               t=b[i];b[i]=b[j];b[j]=t;}
    printf("%d",a[c[1]]);
    for (i=2;i<=n;i++)
     printf(" %d",a[c[i]]);
     printf("\n");
    }
return 0;
system("pause");
}
