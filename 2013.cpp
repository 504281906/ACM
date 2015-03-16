#include <stdio.h>
int main()
{
    int i,n;
    long s;
    while (scanf("%d",&n)!=EOF)
    {
          s=1;
    for (i=n-1;i>=1;i--)
       s=(s+1)*2;
    printf("%ld\n",s);
    }
return 0;
}
