#include <stdio.h>
int main()
{
    int max,min,i,n,m;
    double s;
    while (scanf("%d",&n)!=EOF)
    {
          max=0;s=0;min=101;
          for (i=1;i<=n;i++)
           {
              scanf("%d",&m);
              s+=m;
              if (m>max) max=m;
              if (m<min) min=m;
           }
          printf("%.2lf\n",(s-max-min)/(n-2));
    }
    return 0;
}
