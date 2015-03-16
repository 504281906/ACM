/* ***********************************************
Author        :kuangbin
Created Time  :2013-11-9 13:48:11
File Name     :E:\2013ACM\专题强化训练\区域赛\2013杭州\1001.cpp
************************************************ */

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

char g[220][220];
pair<int,int>p[20];
int a[220][220];
int d[220][220];
bool f[20];
const int INF = 0x3f3f3f3f;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        if(n == 0 && m == 0)break;
        for(int i = 1;i <= n;i++)
            scanf("%s",g[i]+1);
        int cnt = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                if(g[i][j] == '.')
                {
                    p[cnt] = make_pair(i,j);
                    d[i][j] = cnt++;
                }
        if(cnt == 0)
        {
            printf("0\n");
            continue;
        }
        int ans = INF;
        int tot = (1<<cnt);
        for(int i = 0;i < tot;i++)
        {
            for(int j = 0;j < cnt;j++)
                if(i & (1<<j))
                {
                    for(int k = 0; k < 4;k++)
                    {
                        for(int tt = 0;tt < cnt;tt++)
                            f[tt] = false;
                        bool flag = true;
                        for(int t = 0;t < cnt;t++)
                            if(i & (1<<t))
                                if(t != j)
                                {
                                    int x = p[t].first;
                                    int y = p[t].second;
                                    f[d[x][y]] = true;
                                    if(x-1 > 0)
                                    {
                                        if(g[x-1][y] == '#')flag = false;
                                        else f[d[x-1][y]] = true;
                                    }
                                    if(y+1 <= m)
                                    {
                                        if(g[x][y+1] == '#')flag = false;
                                        else f[d[x][y+1]] = true;
                                    }
                                    if(!flag)break;
                                }
                        if(!flag)continue;
                        int x = p[j].first;
                        int y = p[j].second;
                        f[d[x][y]] = true;
                        if(k == 0)
                        {
                            if(x-1 > 0)
                            {
                                if(g[x-1][y] == '#')flag = false;
                                else f[d[x-1][y]] = true;
                            }
                            if(y+1 <= m)
                            {
                                if(g[x][y+1] == '#')flag = false;
                                else f[d[x][y+1]] = true;
                            }
                        }
                        else if(k == 1)
                        {
                            if(x+1 <= n)
                            {
                                if(g[x+1][y] == '#')flag = false;
                                else f[d[x+1][y]] = true;
                            }
                            if(y+1 <= m)
                            {
                                if(g[x][y+1] == '#')flag = false;
                                else f[d[x][y+1]] = true;
                            }
                        }
                        else if(k == 2)
                        {
                            if(x+1 <= n)
                            {
                                if(g[x+1][y] == '#')flag = false;
                                else f[d[x+1][y]] = true;
                            }
                            if(y-1 > 0)
                            {
                                if(g[x][y-1] == '#')flag = false;
                                else f[d[x][y-1]] = true;
                            }
                        }
                        else
                        {
                            if(x-1 > 0)
                            {
                                if(g[x-1][y] == '#')flag = false;
                                else f[d[x-1][y]] = true;
                            }
                            if(y-1 > 0)
                            {
                                if(g[x][y-1] == '#')flag = false;
                                else f[d[x][y-1]] = true;
                            }
                        }
                        if(!flag)continue;
                        for(int t = 0;t < cnt;t++)
                            if(f[t] == false)
                                flag = false;
                        if(!flag)continue;
                        int num = 0;
                        for(int t = 0;t < cnt;t++)
                            if(i & (1<<t))
                                num++;
                        ans = min(ans,num);
                    }
                }
        }
        if(ans == INF)ans = -1;
        cout<<ans<<endl;

    }
    return 0;
}
