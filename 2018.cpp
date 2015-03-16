#include <stdio.h>
int main()
{
    int a[60],i,n;
          a[1]=1;
          a[2]=2;
          a[3]=3;
          a[4]=4;
    while (scanf("%d",&n) && n!=0)
    {
          if (n<=4) printf("%d\n",a[n]);
          else
          {
             for (i=5;i<=n;i++)
               a[i]=a[i-1]+a[i-3];
               printf("%d\n",a[n]);
               }
    }
    return 0;
}
