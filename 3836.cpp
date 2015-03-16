#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#define MAX 20500  // ����������
#define MAXE 50500// �ߵ��������
using namespace std;
// ����Ա�u-->v
struct EDGE
{
    int v; // ��u������ܵ���ĵ�v
    int next; // ��u������ܵ������һ���ߵı��
}edge[MAXE];
int first[MAX];   // first[u] = e���ӵ�u���������һ���ߵı����e(�������ָ�������)
int dfn[MAX];  // dfn[u]���ڵ�u�����Ĵ�����(ʱ���)
int low[MAX];// low[u]����u��u�������ܹ�׷�ݵ��������ջ�нڵ�Ĵ����
int ins[MAX];// �Ƿ���ջ��
int scc[MAX]; // scc[i] = j����i�������ڵ�ǿ��ͨ�����ı��
int out[MAX];
int in[MAX];// ǿ��ͨ�����ĳ���
int n,m;
int num; // ǿ��ͨ��������Ŀ
int index; // ������
stack<int> s;
void DFS(int x)
{
    low[x]=dfn[x]=index++;
    s.push(x);
    ins[x]=1;// ö��ÿһ���ߣ�u-->v
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
    }  // ����ڵ�u��ǿ��ͨ�����ĸ�
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
    int ct[MAX]; // ct[i] = j��ǿ��ͨ����i��j����
    int v;
    memset(ct,0,sizeof(ct));
    if(num==1)return 0;
       // ö��ÿһ����u����outdegree��ct
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
      // ��ǿ��ͨ����
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
