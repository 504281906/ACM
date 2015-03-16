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
	int x,y;
}a[10010];
int cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	int T,n,i;
	scanf("%d",&T);
	int cas=1;
	while (T--){
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d%d",&a[i].x,&a[i].y);
		printf("Case #%d: ",cas++);
		sort(a+1,a+1+n,cmp);
		double ans=0;
		for (i=2;i<=n;i++){
			double k=fabs((a[i].y-a[i-1].y)*1.0/(a[i].x-a[i-1].x));
			if (ans<k) ans=k;
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
