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
	if (a%b==0) return b;
	else return gcd(b,a%b);
}
int a[100010];
int main(){
	int T=1,i,j,p1,p2,n;
	while (~scanf("%d",&n)){
		int flag=1;
		scanf("%d",&a[1]);
		int gg=a[1];
		for (i=2;i<=n;i++){
			scanf("%d",&a[i]);
			gg=gcd(gg,a[i]);
		}
		printf("Case %d: ",T++);
		if (gg==1){
		for (i=1;i<=n;i++){
			if (flag)
				for (j=1;j<i;j++)
					if (gcd(a[j],a[i])==1){
						flag=0;
						p1=j;
						p2=i;
					}
			}
			int gg=1;
			for (i=1;i<=n;i++)
				if (i!=p1 && i!=p2 && a[i]!=1) gg++;
			printf("%d\n",gg);
			printf("%d %d\n",p1,p2);
			for (i=1;i<=n;i++)
				if (i!=p1 && i!=p2 && a[i]!=1) printf("%d %d\n",p1,i);
			printf("\n");
		}
		else printf("-1\n\n");
	}
	return 0;
}
