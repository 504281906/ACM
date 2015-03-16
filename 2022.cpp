#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,i1,j1,n,m,s;
    int a[100][100],b[100][100];
    while (scanf("%d%d\n",&m,&n)!=EOF)
    {
          s=0;
    for (i=1;i<=m;i++)
     for (j=1;j<=n;j++)
      {
          scanf("%d",&a[i][j]);
          b[i][j]=abs(a[i][j]);
      }
    for (i=1;i<=m;i++)
     for (j=1;j<=n;j++)
        if (s<b[i][j]) 
        {s=b[i][j];i1=i;j1=j;}
     printf("%d %d %d\n",i1,j1,a[i1][j1]);
    }
     return 0;    
}
