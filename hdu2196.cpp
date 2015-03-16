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
using namespace std;
struct node{
	int a,b,v,next;
}edge[20005];
int head[20005],w,dp[20005],ans[20005];
void add(int a,int b,int v){
	w++;
	edge[w].a=a;
	edge[w].b=b;
	edge[w].v=v;
	edge[w].next=head[a];
	head[a]=w;
}
void DFS(int x,int father){
	for (int i=head[x];i!=-1;i=edge[i].next){
		int to=edge[i].b;
		if (to==father) continue;
		dp[to]=max(dp[to],dp[x]+edge[i].v);
		DFS(to,x);
	}
}
int main(){
	int n,i,j,v;
	while (~scanf("%d",&n)){
		w=0;
		memset(dp,0,sizeof(dp));
		memset(head,-1,sizeof(head));
		memset(edge,0,sizeof(edge));
		for (i=2;i<=n;i++){
			scanf("%d%d",&j,&v);
			add(i,j,v);
			add(j,i,v);
		}
		DFS(1,-1);
		int k=-1,l1,l2;
		for (i=1;i<=n;i++){
			if (k<dp[i]){
				k=dp[i];
				l1=i;
			}
			dp[i]=0;
		}
		DFS(l1,-1);
		k=-1;
		for (i=1;i<=n;i++){
			if (k<dp[i]){
				l2=i;
				k=dp[i];
			}
			ans[i]=dp[i];
			dp[i]=0;
		}
		DFS(l2,-1);
		for (i=1;i<=n;i++)
			printf("%d\n",max(ans[i],dp[i]));
	}
	return 0;
}
