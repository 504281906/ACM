#include <iostream>
#include <memory.h>
#include <stdio.h>
using namespace std;
#define LL long long

LL dp[31][20000],n,m,row,zt;
LL num[10],pp[10];

// ״̬  0----��Ż������ŵĵ��������� ���²�û��Ӱ��
//       1----���ŵ��м��Ǹ�����  ����һ����Ӱ��
//       2----���ŵĵ�һ������    ����������Ӱ��

void dfs(LL pos,LL status)
{
    if(pos==n)
    {
        dp[row+1][status]+=dp[row][zt];
        return;
    }
    if(num[pos]==0)  // �ϲ�Ϊ0  �����Ժ�Ż��߳�2
    {
        if(pos+2<n&&num[pos+1]==0&&num[pos+2]==0) dfs(pos+3,status);  // ���
        dfs(pos+1,status+2*pp[pos]);
    }
    else if(num[pos]==1)     // �ϲ�Ϊ1  ���Ϊ0
    {
        dfs(pos+1,status);
    }
    else      // �ϲ�Ϊ2 ���Ϊ1
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
        nmax=pp[n];      // ״̬����
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
