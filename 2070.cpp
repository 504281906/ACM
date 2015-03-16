#include <stdio.h>
int main()
{
    int i,j,n;
    __int64 f[100];
    f[0]=0;f[1]=1;
    for (i=2;i<=50;i++)
     f[i]=f[i-1]+f[i-2];
    while (scanf("%d",&n)!=EOF && n!=-1)
      printf("%I64d\n",f[n]);
    return 0;
}
