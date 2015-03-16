#include <stdio.h>
#include <string.h>
int main()
{
    int k,t,n,i,j;
    char s[1000];
    scanf("%d\n",&n);
    for (i=1;i<=n;i++)
    {
        t=0;
        gets(s);
        j=strlen(s);
        for (k=0;k<j;k++)
         if (s[k]<0 ||s[k]>128)
          t++;  
          printf("%d\n",t/2);
    }
return 0;
}
