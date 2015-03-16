#include <stdio.h>
#include <stdlib.h>
void f1(int);
void f2(int);
int main()
{
     int x=10;
     f1(x);
     printf("%d\n",x);system("pause");
}
void f1(int x)
{
     x=20;
     f2(x);
     printf("%d\n",x);system("pause");
}
void f2(int x)
{
     x=30;
     printf("%d\n",x);
     system("pause");
}     
