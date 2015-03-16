#include <stdio.h>
int main()
{
    int i,j,n,m,t,s=0;
    int a[100][100];
    double b[100],c[100],p1,p2;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
       for (i=1;i<=m;i++)
         for (j=1;j<=n;j++)
          scanf("%d",&a[i][j]);
       for (i=1;i<=m;i++)
       {
         p1=0;
         for (j=1;j<=n;j++)
            p1+=a[i][j];
          b[i]=p1/n;
          if (i==1) printf("%.2lf",b[1]);
          else printf(" %.2lf",b[i]);
       }
       printf("\n");
       for (i=1;i<=n;i++)
       {
         p2=0;
         for (j=1;j<=m;j++)
            p2+=a[j][i];
            c[i]=p2/m;
          if (i==1) printf("%.2lf",c[1]);
          else printf(" %.2lf",c[i]);
       }
       printf("\n");
       for (i=1;i<=m;i++)
         {
          t=1;
         for (j=1;j<=n;j++)
           if (a[i][j]<c[j]) t=0;
            if (t==1) s++;
         }
         printf("%d\n\n",s);   
    }
    return 0;
}
