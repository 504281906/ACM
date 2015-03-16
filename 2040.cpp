#include <stdio.h>
int yueshu(int a)
{
    int k,s;
    s=0;
    for (k=1;k<a;k++)
     if (a%k==0) s+=k;
    return s;
}
int main()
{
    int i,a,b,n;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        if (yueshu(a)==b && yueshu(b)==a) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
