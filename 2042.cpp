#include <stdio.h>
int main()
{
    int i,n,s,j,k;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&k);
        s=3;
        for (j=1;j<=k;j++)
        s=(s-1)*2;
        printf("%d\n",s); 
    }
    return 0;
} 
