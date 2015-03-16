#include <stdio.h>
int main()
{
    int j,n,m,i,a[100];
  while (scanf("%d%d",&n,&m)!=EOF && n!=0 &&m!=0)
  {
        for (i=0;i<n;i++)
         scanf("%d",&a[i]);  
         if (a[0]<m)  
         {
         printf("%d",a[0]);
         i=1;
         while (a[i]<=m)
         {
               printf(" %d",a[i]);
               i++;
         }
         printf(" %d",m);
         for (j=i;j<n;j++)
         printf(" %d",a[j]);
         printf("\n");
         }
         else 
         {
                 printf("%d",m);
                 for (i=0;i<n;i++)
                  printf(" %d",a[i]);
                   printf("\n");
                  }
  }
}

