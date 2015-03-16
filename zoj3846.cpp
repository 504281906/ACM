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
int gcd(int a,int b){
	return a%b==0?b:gcd(b,a%b);
}
int a[100010];
int main(){
	int n,i;
	int cas=1;
	while (~scanf("%d",&n)){
		scanf("%d",&a[1]);
		int gg=a[1];
		for (i=2;i<=n;i++){
			scanf("%d",&a[i]);
			gg=gcd(gg,a[i]);
		}
		printf("Case %d: ",cas++);
		if (gg==1){
			printf("%d\n",2*(n-1));
			for (i=2;i<=n;i++)
				printf("1 %d\n",i);
			for (i=2;i<=n;i++)
				printf("1 %d\n",i);
			printf("\n");
		}
		else{
			printf("-1\n\n");
		}
	}
	return 0;
}
