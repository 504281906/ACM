#include <stdio.h>
#include <string.h>
int main()
{
    int i,l,j,n,a,b,c,d;
    char s[101];
    scanf("%d\n",&n);
    for (i=1;i<=n;i++)
    {
        a=0;b=0;c=0;d=0;
        gets(s);
        l=strlen(s);
        if (l<8 || l>16) {printf("NO\n");continue;}
        else 
        {
             for (j=1;j<=l;j++)
               {
                 if (s[j]>='a' && s[j]<='z') a=1;
                 if (s[j]>='A' && s[j]<='Z') b=1;
                 if (s[j]>='0' && s[j]<='9') c=1;
                 if (s[j]=='~'||s[j]=='!'|| s[j]=='@'||s[j]=='#'|| s[j]=='$' ||s[j]=='%'|| s[j]=='^') d=1;
               }
             if (a+b+c+d>=3) printf("YES\n");
             else printf("NO\n");
        }
    }
    return 0;
}
