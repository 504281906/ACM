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
	int a,b,c;
}f[100];
int main(){
	int T,n,a,i,b,c;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d%d",&a,&b,&c);
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d%d%d",&f[i].a,&f[i].b,&f[i].c);
			int flag=0;
		for (int i=1;i<1<<(n+1);i++){
			int j=i;
			int aa=0,bb=0,cc=0,t=1;
			while (j){
				if (j%2){
					aa+=f[t].a;
					bb+=f[t].b;
					cc+=f[t].c;
				}
				j/=2;
				t++;
			}
			if (aa==a && bb==b && cc==c){
				flag=1;
				break;
			}
		}
		if (flag) printf("Case %d: yes\n",cas);
		else printf("Case %d: no\n",cas);
	}
	return 0;
}
