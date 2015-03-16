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
int a[1010010];
int p[100000];
void INIT(){
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	int t=0;
	for (int i=2;i<=1010000;i++){
		if (a[i]==0)
			p[++t]=i;
		for (int j=1,k;j<=t && ((k=i*p[j])<=1010000);j++)
		{
			a[k]=1;
			if (i % p[j]==0) break; 
		} 
	}
	t=1;
	for (int i=1;i<=1000001;i++){
		if (i<p[t]) a[i]=p[t];
		else {
			t++;
			a[i]=p[t];
		}
	}
}
int main(){
	INIT();
	int T;
	//freopen("in.txt","r",stdin);
	//fropen("out.txt","w",stdout)
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		int n,k;
		scanf("%d",&n);
		LL ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			ans+=a[k];
		}
		printf("Case %d: %lld Xukha\n",cas,ans);
	}
	return 0;
}
