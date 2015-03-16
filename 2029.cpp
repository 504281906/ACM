#include <stdio.h>
#include <string.h>
int main()
{
    int f,n,i,j,t;
    char s[101];
    scanf("%d",&n);
    for (t=1;t<=n;t++)
    {
        f=1;  
        scanf("%s",&s);
        j=strlen(s);
         for (i=0;i<=j/2;i++)
          if (s[i]!=s[j-i-1]) 
             f=0;
        f==1?printf("yes\n"):printf("no\n");
    }
return 0;
}
