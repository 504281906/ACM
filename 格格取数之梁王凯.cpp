#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
#include <iomanip>
#include<iostream>
#include<algorithm>
using namespace std ;
const int N=200 ;
const int M=N*N ;
const int inf=1<<30 ;
struct node
{
	int u,v,c,cost,next;
}edge[M];
int pp[N],pre[N],head[N],vist[N],dist[N];
int top ;
int a[110][110];

void add(int u ,int v,int c,int cost)
{
	edge[top].u=u;
	edge[top].v=v;
	edge[top].c=c;
	edge[top].cost=cost;
	edge[top].next=head[u];
	head[u]=top++;
	edge[top].u=v;
	edge[top].v=u;
	edge[top].c=0;
	edge[top].cost=-cost;
	edge[top].next=head[v];
	head[v]=top++;
}

int SPFA(int s,int t)
{
	int u , v ;
	memset(vist,0,sizeof(vist));
	memset(pre,-1,sizeof(pre));
    for(int i = 0 ; i <= t ; i++)  dist[i]=inf ;
    vist[s]=1;dist[s]=0;pre[s]=s;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
    	 u=q.front();
    	 q.pop();
    	 vist[u]=0;
    	 for(int i =head[u];i!=-1;i=edge[i].next)
    	 {
    	 	   v=edge[i].v;
    	 	   if(edge[i].c && dist[v] > dist[u]+edge[i].cost)
    	 	   {
    	 	   	    dist[v] = dist[u]+edge[i].cost ;
    	 	   	     pre[v]=u;
    	 	   	     pp[v]=i;
    	 	   	     if(!vist[v]);
    	 	   	     {
    	 	   	     	   vist[v]=1;
    	 	   	     	   q.push(v);
    	 	   	     }
    	 	   }
        }
    }
	if(dist[t]==inf) return 0;
	return 1 ;
}

int MFMC(int s,int t)
{
	int mincost=0,flow=0,minflow ;
	while(SPFA(s,t))
	{
		  minflow=inf;
		  for(int i=t;i!=s;i=pre[i])
		      minflow=min(minflow,edge[pp[i]].c);
		  for(int i=t;i!=s;i=pre[i])
		  {
		  	    edge[pp[i]].c -= minflow;
		  	    edge[pp[i]^1].c += minflow;
		  }    
		  flow += minflow;
		  mincost += dist[t]*minflow ;
	}
	return mincost ;
}

int main()
{
	int n,m,t,k=1; 
	char ch ; 
	scanf("%d",&t);
	while(t--)
	{
		
	       scanf("%d%d",&n,&m);
		   top=0;
		   memset(head,-1,sizeof(head));
		   int s=0,t=n+m+3 ,r=n+m+1,M=n+m+2;
		   if(m>n)
		   {
		   	  int w = n ;
		   	  n=m; m=w ;
		   }
		  for(int i = 1 ; i <= n ; i++)
	       for(int j = 1 ; j <= m ; j++)
	         {
	         	   scanf("%d",&a[i][j]);
	         	   add(i,n+j,1,a[i][j]);
	         }

		   for(int i = 1 ; i <= n ; i++)
		    {
		          add(s,i,1,0) ;
		          add(r,i,inf,0);
		          add(M,i,inf,0);
		    }
	       for(int j = 1 ; j <= m ; j++)
	        {
	             add(n+j,t,1,0);
	             add(n+j,M,inf,0);
	        }
		     add(s,r,n-m,0);
		 int ans=MFMC(s,t);
		 printf("Case %d: %d\n",k++,ans);     
	  
    }
	return 0;
}	
