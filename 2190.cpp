#include <cstdio>
int main()
{
    int T,dp[35],i;
    dp[1]=1;dp[2]=3;
    for(i=3;i<=30;i++)
       dp[i]=dp[i-1]+dp[i-2]*2;
       //dp[i-1]就是多1米全部放长为1米的方块
       //dp[i-2]就是腾出2米放入一个2米的方块，但是腾出的2米刚好是2种方法，所以乘以2.
    scanf("%d",&T);
    while(T--)
    {
        int N;
        scanf("%d",&N);
        printf("%d\n",dp[N]);
    }
    return 0;
}

