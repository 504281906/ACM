#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;
#define LL long long

LL dp[31][20000],n,m,row,zt;
LL num[10],pp[10];

// 状态  0----横放或者竖放的第三个格子 对下层没有影响
//       1----竖放的中间那个格子  对下一层有影响
//       2----竖放的第一个格子    对下两层有影响

void dfs(LL pos,LL status)
{
    if(pos==n)
    {
        dp[row+1][status]+=dp[row][zt];
        return;
    }
    if(num[pos]==0)  // 上层为0  这层可以横放或者成2
    {
        if(pos+2<n&&num[pos+1]==0&&num[pos+2]==0) dfs(pos+3,status);  // 横放
        dfs(pos+1,status+2*pp[pos]);
    }
    else if(num[pos]==1)     // 上层为1  这层为0
    {
        dfs(pos+1,status);
    }
    else      // 上层为2 这层为1
    {
        dfs(pos+1,status+pp[pos]);
    }
}

void change()
{
    LL now=zt,k=-1;
    memset(num,0,sizeof(num));
    if(now==0) return;
    while(now)
    {
        num[++k]=now%3;
        now/=3;
    }
}

int main()
{
    LL i,nmax;
    pp[0]=1;
    for(i=1;i<=9;i++) pp[i]=pp[i-1]*3;
    while(scanf("%lld%lld",&n,&m)&&(m||n))
    {
        if((m*n)%3!=0) {printf("0\n"); continue;}
        nmax=pp[n];      // 状态总数
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(row=0;row<=m-1;row++)
        {
            for(zt=0;zt<nmax;zt++)
            {
                if(dp[row][zt])
                {
                    change();
                    dfs(0,0);
                }
            }
        }
        printf("%lld\n",dp[m][0]);
    }
    return 0;
}
