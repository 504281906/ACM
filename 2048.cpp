#include <stdio.h>
double a[22]={1,1};
double b[22]={0,0,1,2};
int main()
{
    int i,m,n;
    for(i=1;i<21;i++)
    {
        a[i]=i*a[i-1];
    }

    for(i=3;i<21;i++)
    b[i]=(i-1)*(b[i-1]+b[i-2]);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%.2lf%%\n",b[m]*100/a[m]);
    }
}
