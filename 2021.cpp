#include <stdio.h>
int main()
{
    int i,j,n,s,m;
    while (scanf("%d",&n) && n!=0)
    {
          s=0;
          for (i=1;i<=n;i++)
           {
             scanf("%d",&m);
             s+=m/100;
             m=m%100;
             s+=m/50;
             m=m%50;
             s+=m/10;
             m=m%10;
             s+=m/2;
             m=m%2;
             s+=m;
           }
          printf("%d\n",s);
    }
return 0;
}
