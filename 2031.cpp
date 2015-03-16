#include <stdio.h>
int main()
{
    int i,j,n,m;
    int a[100];
    while (scanf("%d%d",&n,&m)!=EOF)
    {
          if (n<0) {printf("-");n=0-n;}
          i=1;
          while (n!=0)
          {
           a[i]=n%m;
           n=n/m;
           i++;
          }
          for (j=i-1;j>=1;j--)
           if (a[j]<10) printf("%d",a[j]);
           else 
           {
                if (a[j]==10) printf("A");
                if (a[j]==11) printf("B");
                if (a[j]==12) printf("C");
                if (a[j]==13) printf("D");
                if (a[j]==14) printf("E");
                if (a[j]==15) printf("F");
                if (a[j]==16) printf("D");
           }
           printf("\n");
    }
    return 0;
}
