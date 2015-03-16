#include <stdio.h>
int f[10000];
int find(int n)
{
    if (f[n]!=n) f[n]=find(f[n]);
    return f[n];
}
int main()
{
    int i,b,a,t,n,m;
    while (~scanf("%d%d%d",&m,&n,&t))
    {
        for (i=1;i<=m;i++)
            f[i]=i;
        for (i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            a=find(a);
            b=find(b);
            f[a]=b;
        }
        for (i=1;i<=t;i++)
        {
            scanf("%d%d",&a,&b);
            a=find(a);
            b=find(b);
            if (a==b)
                printf("YES\n");
            else 
                printf("NO\n");
        }
    }
    return 0;
}
