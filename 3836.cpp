#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#define MAX 20500  // 点的最大数量
#define MAXE 50500// 边的最大数量
using namespace std;
// 假设对边u-->v
struct EDGE
{
    int v; // 从u点出发能到达的点v
    int next; // 从u点出发能到达的下一条边的编号
}edge[MAXE];
int first[MAX];   // first[u] = e：从点u出发的最后一条边的编号是e(“最后”是指最后输入)
int dfn[MAX];  // dfn[u]：节点u搜索的次序编号(时间戳)
int low[MAX];// low[u]：是u或u的子树能够追溯到的最早的栈中节点的次序号
int ins[MAX];// 是否在栈中
int scc[MAX]; // scc[i] = j：第i个点所在的强连通分量的编号
int out[MAX];
int in[MAX];// 强连通分量的出度
int n,m;
int num; // 强连通分量的数目
int index; // 次序编号
stack<int> s;
void DFS(int x)
{
    low[x]=dfn[x]=index++;
    s.push(x);
    ins[x]=1;// 枚举每一条边：u-->v
    for(int k=first[x];k!=-1;k=edge[k].next)
    {
        int v=edge[k].v;
        if(dfn[v]==0)
        {
            DFS(v);
            low[x]=min(low[x],low[v]);
        }
        else if(ins[v])
            low[x]=min(dfn[v],low[x]);
    }  // 如果节点u是强连通分量的根
    if(low[x]==dfn[x])
    {
        int v;
        num++;
        do{
        v=s.top();
        s.pop();
        ins[v]=0;
        scc[v]=num;
        }while(v!=x);
    }
}
void init()
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(first,-1,sizeof(first));
    memset(ins,0,sizeof(ins));
    memset(out,0,sizeof(out));
    memset(in,0,sizeof(in));
    memset(scc,0,sizeof(scc));
    index=1;
    num=0;
    int a,b,e=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        edge[e].v=b;
        edge[e].next=first[a];
        first[a]=e;
        e++;
    }

}
int getans()
{
    int ct[MAX]; // ct[i] = j：强连通分量i有j个点
    int v;
    memset(ct,0,sizeof(ct));
    if(num==1)return 0;
       // 枚举每一个点u：求outdegree和ct
    for(int i=1;i<=n;i++)
    {
        ct[scc[i]]++;
        for(int k=first[i];k!=-1;k=edge[k].next)
        {
            v=edge[k].v;
            if(scc[i]!=scc[v])
            {
                out[scc[i]]++;
                in[scc[v]]++;
            }
        }
    }
    int num1=0,num2=0;
    for(int i=1;i<=num;i++)
    {
        if(in[i]==0)
        {
            num1++;
        }
        if(out[i]==0)
        {
            num2++;
        }
    }
    return max(num1,num2);
}
void solve()
{
      // 求强连通分量
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
        {
            DFS(i);
        }
    }
    cout<<getans()<<endl;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        solve();
    }
return 0;
}
