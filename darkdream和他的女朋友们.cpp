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
int main(){
	int T,n,i;
	double k,p;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		double ans=0;
		for (i=1;i<=n;i++){
			scanf("%lf%lf",&k,&p);
				ans+=k*p;
		}
		printf("%.2f\n",ans);
	}
	return 0;
}
