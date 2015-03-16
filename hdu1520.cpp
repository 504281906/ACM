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
int w;
struct node{
	int a,b,next;
}edge[14000];
int head[14000];
int dp[7000][3];
int a[7000];
void add(int x,int y){
	w++;
	edge[w].a=x;
	edge[w].b=y;
	edge[w].next=head[x];
	head[x]=w;
}
void DFS(int x,int y){
	dp[x][0]=0;
	dp[x][1]=a[x];
	int i;
	for (i=head[x];i!=-1;i=edge[i].next){
		int to=edge[i].b;
		if (to==y) continue;
		DFS(to,x);
		dp[x][0]+=max(dp[to][0],dp[to][1]);
		dp[x][1]+=dp[to][0];
	}
}
int main(){
	int n,x,y,i;
	while (~scanf("%d",&n)){
		w=0;
		memset(head,-1,sizeof(head));
		memset(dp,0,sizeof(dp));
		memset(edge,0,sizeof(edge));
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		while (~scanf("%d%d",&x,&y) && (x&&y)){
			add(x,y);
			add(y,x);
		}
		DFS(1,-1);
		printf("%d\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}
