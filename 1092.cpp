#include<stdio.h>
int main()
{
int a,b,n;
while(scanf("%d\n",&n)&&n!=0)
{
b=0;
while(n--)
{
scanf("%d\n",&a);
b+=a;
}
printf("%d\n",b);
}
return 0;
}
