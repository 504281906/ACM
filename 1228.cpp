#include <stdio.h>
#include <string.h>
char num[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int search(char ch[])
{
    int i;
    for(i=0;i<10;i++)
    {
           if(strcmp(ch,num[i])==0)
           break;
    }
    return i;
}
int main()
{
    char count[10];
    int a,b;
    while(1)
    {
            a=0;
            while(scanf("%s",&count)&&strcmp(count,"+")!=0)
            a=a*10+search(count);
            b=0;
            while(scanf("%s",&count)&&strcmp(count,"=")!=0)
            b=b*10+search(count);
            if(a==0&&b==0) return 0;
            else
            {
                     printf("%d\n",a+b);
            }
    }
    return 0;
}
