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
#define pi acos(-1)
using namespace std;
int f[200010][2010];
int a[200010],vis[200010];
void DFS(int p,int k){
	int ans=k;
	int flag=1;
	for (int i=1;i<=f[p][0];i++){
		if (!vis[f[p][i]]){
			int gg=f[p][i];
			if (k==1 && f[p][0]!=0){
				flag=0;
				ans=2;
				DFS(gg,2);
			}
			if (k==2 && f[p][0]>2){
				flag=0;
				ans=3;
				DFS(gg,1);
			}
		}
	}
	if (flag) ans=1;
	vis[p]=1;
	a[p]=ans;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=1,n,i,k;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		scanf("%d",&k);
		for (i=2;i<=n;i++){
			scanf("%d",&k);
			f[k][0]++;
			f[k][f[k][0]]=i;
		}
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++){
			if (!vis[i])
				DFS(i,1);
		}
		int ans=0;
		for (i=1;i<=n;i++)
			ans+=a[i];
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}
