#include<stdio.h>
#include<string.h>
inline int max (int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int t,a[4],dp[10005];
    int i,j,n;
    scanf("%d",&t);
    a[1]=150;
    a[2]=200;
    a[3]=350;
    while (t--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for (i=1; i<=n; ++i)
        {
            for (j=1; j<=3; ++j)
            {
                if (i>=a[j]) dp[i]=max(dp[i],dp[i-a[j]]+a[j]);
            }
        }
        printf("%d\n",n-dp[n]);
    }
    return 0;
}

