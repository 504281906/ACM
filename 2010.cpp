#include <stdio.h>
int main()
{
  int s,m,n,i,a,b,c;
  while (scanf("%d%d",&m,&n)!=EOF)
  {
        s=0;
        for (i=m;i<=n;i++)
         {
                          a=i/100;
                          b=i/10%10;
                          c=i%10;
                          if (a*a*a+b*b*b+c*c*c==i) 
                           {
                             s++;
                             if (s==1) 
                             printf("%d",i);
                             else printf(" %d",i);
                           }
         }
  if (s==0) printf("no\n");
  else printf("\n");
  }  
  return 0;
}
