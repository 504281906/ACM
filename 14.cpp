#include <stdio.h>
#include <stdlib.h>
int main()
{
      int i;
      double s=1.0,k;
      scanf("%lf",&k);
       i=2;   
      while (s<=k)
       {
           s=s+1/i;
           i=i+1;   
       }
       
     printf("%d",i);
     system("pause");
     return 0; 
}
