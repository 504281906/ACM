#include <stdio.h>
int main()
{
   long n,i,m,x,y;
   while (scanf("%d%d",&m,&n)!=EOF)
   {
     if (m>n) {x=m;m=n;n=x;}
      x=0;y=0;
     for (i=m;i<=n;i++)
      if (i%2==0) x+=i*i;
       else y+=i*i*i;
       printf("%d %d\n",x,y);
   } 
   return 0;  
}
