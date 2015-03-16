#include <stdio.h>
int main()
{
    int n,i,j,a,b;
    __int64 f[101];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        f[1]=1;f[2]=2;
        scanf("%d%d",&a,&b);
        for (j=3;j<=b;j++)
          f[j]=f[j-1]+f[j-2];
        printf("%I64d\n",f[b-a]);  
    }
    return 0;
}
