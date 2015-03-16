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
int b[1000010],a[1000010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	int T,i,j,n;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=0;
		int t=a[n];
		for (i=n-1;i>=1;i--){
			if (a[i]>t) ans++;
			else {
				t=a[i];
			}
		} 
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
