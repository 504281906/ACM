#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

const int inf = 1<<30;
const int L = 200000;

struct Edges
{
    int x,y,w,next;
} e[L<<2];

int head[L];
int dis[L];
int vis[L];

void AddEdge(int x,int y,int w,int k)
{
    e[k].x = x,e[k].y = y,e[k].w = w,e[k].next = head[x],head[x] = k;
}
int relax(int u,int v,int c)
{
    if(dis[v]>dis[u]+c)
    {
        dis[v] = dis[u]+c;
        return 1;
    }
    return 0;
}

int SPFA(int src)
{
    int i;
    dis[src] = 0;
    queue<int> Q;
    Q.push(src);
    vis[src] = 1;
    while(!Q.empty())
    {
        int u,v;
        u = Q.front();
        Q.pop();
        vis[u] = 0;
        for(i = head[u]; i!=-1; i=e[i].next)
        {
            v = e[i].y;
            if(relax(u,v,e[i].w)==1 && !vis[v])
            {
                Q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    int t,n,m;
    int i,j;
    scanf("%d%d",&n,&m);
    memset(e,-1,sizeof(e));
    for(i = 1; i<=n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
        head[i] = -1;
    }
    for(i = 0; i<m; i++)
    {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        AddEdge(x,y,w,i);
    }
    SPFA(1);
    for(i = 2; i<=n; i++)
        printf("%d\n",dis[i]);
    return 0;
}

