#include <stdio.h>
int main()
{
    int n,m,i,j;
    double max,k;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        max=0;
        scanf("%d",&m);
        for (j=1;j<=m;j++)
        {
            scanf("%lf",&k);
            if (max-k<0) max=k;
        }
        printf("%.2lf\n",max);
    }
    return 0;
}
