#include <stdio.h>
#include <stdlib.h>
int q;
int move (int n,int a,int b,int c)
{
     if(n==1) 
     { printf("%c-->%c\n",a,c);
       q++;
     }
     else {
          move(n-1,a,c,b);
          printf("%c-->%c\n",a,c);
          q++;
          move(n-1,b,a,c);      
     }
}
main ()
{
     int n;
     scanf("%d",&n);
     move(n,'a','b','c');
     printf("%d\n",q);
     system("pause");
}
