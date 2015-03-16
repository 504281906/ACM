#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define eps 1e-8
const int MAXN 10010; 
struct Edge
{
	int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN*2];
int fa[MAXN];
int deep[MAXN];
int num[MAXN];
int p[MAXN];
int fp[MAXN];
int son[MAXN];
int pos;
int init()
{
  tot  = 0  ;
  memset(head,-1,sizeof(head));
  pos = 0 ;
  memset(son,-1,sizeof(son));
}
void addedge(int u ,int v)
{
	edge[tot].to = v ;
	edge[tot].next = head[u];
	head[u] = tot ++;
}
void dfs1(int u ,int pre,int d)
{
	deep[u] = d ;
	fa[u] = pre;
	num[u] = 1;
	for(int i = head[u],i != -1 ; i = edge[i].next)
	{
		int v = edge[i].to ;
		if(v != pre)
		{
			 dfs1(v,u,d+1);
			 num[u] += num[v];
			 if(son[u] = -1 || num[v] > num[son[u]])
			 {
			 	  son[u] = v;
			 }
		}
	}
}
void getpos(int u ,int sp)
{
	top[u] = sp;
	p[u] = pos ++ ;
	fp[p[u]] = u; 
	if(son[u] == -1 ) return;
	getpos(son[u])
}
using namespace std;
int main()
{
	return 0;
}

