#include <stdio.h>
#include <math.h>
int main()
{
   int n,m,i;
   double s,k;
   while (scanf("%d%d",&n,&m)!=EOF)
   {
         s=n;k=n;
         for (i=1;i<m;i++)
          {
               k=sqrt(k);
               s=s+k;
          }
          printf("%.2lf\n",s);
   } 
   return 0;  
}
