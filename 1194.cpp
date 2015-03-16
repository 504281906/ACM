#include<stdio.h>
int main()
{
    int n,a,b,x,y;
while(scanf("%d",&n)!=EOF)
{
   while(n--)
   {
     scanf("%d%d",&a,&b);
     x=a+b;
     y=a-b;
     if(a>=b&&x>=0&&y>=0&&(x%2==0)&&(y%2==0))
       printf("%d %d\n",x/2,y/2);
     else                                  
       printf("impossible\n");
    }
}
return 0;
}
