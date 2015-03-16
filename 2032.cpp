#include<stdio.h>
int main()
{
    int n, num[31][31];
    int i, j, k;
    while(scanf("%d",&n)!=EOF)
    {
          for(i=1;i<=n;i++)
             for(j=1;j<=i;j++)
          {
               if(i==j||j==1)
               {
                  num[i][j]=1;
                  printf(i==j?"%d\n":"%d ",num[i][j]);
               }
               else
                {
                  num[i][j]=num[i-1][j-1]+num[i-1][j];
                  printf(i==j? "%d\n":"%d " , num[i][j] );
                }
          }
          printf("\n");
    }
    return 0; 
}
