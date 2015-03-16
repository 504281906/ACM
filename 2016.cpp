#include <stdio.h>
int main()
{
     int n,t,i,a[101],j,min;
     while (scanf("%d",&n) !=EOF && n!=0)
     {
           min=32767;
           for (i=0;i<n;i++)
           {
               scanf("%d",&a[i]);
               if (min>a[i]) {j=i;min=a[i];}
           }
           t=a[0];
           a[0]=a[j];
           a[j]=t;
           printf("%d",a[0]);
           a[0]=0;
           for (i=1;i<n;i++)
            {printf(" %d",a[i]);a[i]=0;}
            printf("\n");           
     }
     return 0;
}
