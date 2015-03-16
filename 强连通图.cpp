#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<queue>
#include <iomanip>
#include<iostream>
#include<algorithm>
using namespace std ;
const int N=20100 ;
int low[N],dfn[N],vist[N],in[N],out[N],num[N],head[N],stack[N];
int dfsn,sum,cnt,top ;

struct node
{
	int v,next;
}edge[4*N];

void add(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u)  
{
    int x;
    low[u]=dfn[u]=++dfsn;
    stack[top++]=u;
    vist[u]=true;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vist[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])   
    {
        sum++;      
        do         
        {
            x=stack[--top];
            vist[x]=0;
            num[x]=sum;  
        }
        while(x!=u);
    }
}

void tarjan(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vist,0,sizeof(vist));
    top=dfsn=sum=0;
    for(int i=1; i<=n; i++)
        if(!dfn[i]) dfs(i);
}

int main()
{
	int n,m,a,b;
	while(~scanf("%d%d",&n,&m))
	{
		memset(head,-1,sizeof(head));cnt=0;
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		for(int i = 0 ; i < m ; i++)
		{
			  scanf("%d%d",&a,&b);
			
			  add(a,b);
		}
	    tarjan(n);
	    for(int i = 1 ; i <= n ;i++)
		{
		   for(int j=head[i]; j!=-1; j=edge[j].next)
			{
				int v=edge[j].v ;
				if(num[i]!=num[v])
				{
					  in[num[v]]++;
					  out[num[i]]++;
				}
			} 
		}
		int sum1=0,sum2=0;
		for(int i = 1 ; i <= sum ; i++)
		{
			if(!in[i])  sum1++;
			if(!out[i]) sum2++;  
		}
		if(sum==1) printf("0\n");
		else printf("%d\n",max(sum1,sum2));
	}
	   return 0;
}
