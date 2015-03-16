#include <stdio.h>
int main()
{
   int n,a,b,c,i;
   double j;
   while (scanf("%d",&n)!=EOF)
   {
         if (n==0) break;
         else
         {  
         a=0;b=0;c=0;
         for (i=1;i<=n;i++)
         {
             scanf("%lf",&j);
             if (j<0) a++; 
              else if (j>0) c++;
               else b++;
         } 
         printf("%d %d %d\n",a,b,c);
         }
   } 
   return 0;  
}
