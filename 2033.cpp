#include <stdio.h>
int main()
{
    int i,j,n,k;
    int a[4],b[4],c[4];
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        c[1]=0;c[2]=0;c[3]=0;
        scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&b[1],&b[2],&b[3]);
        for (j=3;j>1;j--)
         {
            c[j]+=a[j]+b[j];
            if (c[j]>=60) 
            {
               c[j-1]++;
               c[j]-=60;
            }
         }
         c[1]+=a[1]+b[1];
         printf("%d %d %d\n",c[1],c[2],c[3]);
    }
    return 0;
}
