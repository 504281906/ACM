#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int c[22][20];
int b[20];
int d[20];
int dp[1<<22];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int G,B,S;
    int n,t;
    while(scanf("%d%d%d",&G,&B,&S) == 3)
    {
        if(G == 0 && B == 0 && S == 0)break;
        memset(c,0,sizeof(c));
        for(int i = 0;i < B;i++)
        {
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&t);
                c[i][t]++;
            }
        }
        dp[0] = 0;
        int tot = (1<<B);
        for(int i = 1;i < tot;i++)
        {
            dp[i] = -10000000;
            for(int j = 1;j <= G;j++)
                b[j] = 0;
            for(int j = 0;j < B;j++)
                if((i&(1<<j)) == 0)
                {
                    for(int k = 1;k <= G;k++)
                    {
                        b[k] += c[j][k];
                        while(b[k] >= S)
                            b[k] -= S;
                    }
                }
            //cout<<i<<"*"<<endl;
            //for(int j = 1;j <= G;j++)
                //cout<<b[j]<<endl;
            for(int j = 0;j < B;j++)
                if(i & (1<<j))
                {
                    for(int k = 1;k <= G;k++)
                        d[k] = b[k];
                    int cnt = 0;
                    for(int k = 1;k <= G;k++)
                    {
                        d[k] += c[j][k];
                        while(d[k] >= S)
                        {
                            d[k] -= S;
                            cnt++;
                        }
                    }
                    if(cnt > 0)dp[i] = max(dp[i],cnt + dp[i^(1<<j)]);
                    else dp[i] = max(dp[i],cnt - dp[i^(1<<j)]);
                }

        }
        printf("%d\n",dp[tot-1]);
    }
    return 0;
}
