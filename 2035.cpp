#include <stdio.h>
int main()
{
    int n,m,i,s;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
          if (n==0 && m==0) break;
          s=n;
          for (i=1;i<m;i++)
          {
             if (s>1000) 
                s=s%1000;
             s=s*n;    
          }
          printf("%d\n",s%1000);
    }
    return 0;
}
