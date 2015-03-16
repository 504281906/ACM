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
struct node{
	int q,w;
}f[110];
int cmp(node a,node b){
	if (a.q==b.q)
		return a.w<b.w;
	else return a.q<b.q;
}
int main(){
	int n,k,i,j;
	int a[110];
	scanf("%d%d",&n,&k);
	int mi=1000,ma=-1;
	for (i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int s=a[i]/k;
		f[i].q=s;
		f[i].w=a[i]-s*k;
	}
	sort(f+1,f+n+1,cmp);
	if (f[n].q-f[1].q>1 || (f[n].q-f[1].q==1 && f[n].w-f[1].w>=1)) printf("NO\n");
	else{
		printf("YES\n");
		for (i=1;i<=n;i++)
		{
			printf("1");
			for (j=2;j<=a[i];j++)
			{
				int s=j%k;
				if (s==0) s=k;
				printf(" %d",s);
			}
			cout<<endl;
		}
	}
	return 0;
}
