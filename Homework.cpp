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
#define max 5000000
int a[max+10],p[max+10];
int ans[max*2+5];
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,k=0,n;
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	for (i=2;i<=max;i++)
	{
		if (a[i]==0)
			p[++k]=i;
		for (j=1,n;p[j]!=0 && ((n=i*p[j])<=max);j++)
		{
			a[n]=1;
			if (i % p[j]==0) break;
		}
	}
	memset(ans,0,sizeof(ans));
	for (i=1;i<=k;i++)
		for (j=p[i];j<=max*2;j+=p[i])
			ans[j]++;
	int T,aa,bb,kk;
	scanf("%d",&T);
	int cas=1;
	while (T--){
		scanf("%d%d%d",&aa,&bb,&kk);
		int ant=0;
		for (i=aa;i<=bb;i++)
			if (ans[i]==kk) ant++;
		printf("Case #%d: %d\n",cas++,ant);
	}
	return 0;
}

