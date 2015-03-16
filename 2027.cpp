#include <stdio.h>
int main()
{
    int k,j,n,a=0,e=0,i=0,o=0,u=0;
    char s[100];
    scanf("%d\n",&n);
    for (k=1;k<=n;k++)
    {
        a=0,e=0,i=0,o=0,u=0;
        gets(s);
        for (j=0;s[j]!='\0';j++)
        {
           if (s[j]=='a') a++;
           if (s[j]=='e') e++; 
           if (s[j]=='i') i++; 
           if (s[j]=='o') o++; 
           if (s[j]=='u') u++; 
        }
         printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,e,i,o,u); 
        if (k!=n) printf("\n");
    }
    return 0;
}
