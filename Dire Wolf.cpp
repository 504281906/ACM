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
int a[300],b[300];
int main(){
	int T,n,i,j,l;
	scanf("%d",&T);
	int cas=1;
	while (T--){
		LL ans=0;
		scanf("%d",&n);
		memset(b,0,sizeof(b));
		for (i=1;i<=n;i++){
			scanf("%d",&a[i]);
			ans+=a[i];
		}
		for (i=1;i<=n;i++)
			scanf("%d",&b[i]);
		printf("Case #%d: ",cas++);
		for (i=1;i<=n;i++){
			if (n-i+1==3){
				int gg=b[2]+b[3];
				if (gg>2*b[2]) gg=2*b[2];
				if (gg>b[3]+2*b[1]) gg=2*b[1]+b[3];
				if (gg>b[1]+2*b[3]) gg=2*b[3]+b[1];
				if (gg>b[1]+b[2]) gg=b[1]+b[2];
				ans+=gg;
				break;
			}else{
			LL s=0;int k=0;
			int max=-1,pos,hit=0;
			for (j=1;j<=n-i+1;j++){
				if (j==1 || j==(n-i+1)){
					if (max<b[j]){
						max=b[j];
						pos=j;
						if (j==1) hit=b[j+1];
						else hit=b[n-i];
					}else{
						if (max==b[j]){
							if (j==1 && hit>b[j+1]){
								hit=b[j+1];
								pos=j;
							}else if (j==(n-i+1) && hit>b[j-1]){
								hit=b[j-1];
								pos=j;
							}
						}
					}
				}else{
					int gg=b[j]*2-b[j-1]-b[j+1];
					if (max<gg && b[j]>=b[j-1]+b[j+1]){
						max=gg;
						pos=j;
						hit=b[j-1]+b[j+1];
					}else{
						if (max==gg && hit>b[j-1]+b[j+1]){
							hit=b[j-1]+b[j+1];
							pos=j;
						}
					}
				}
			}
			ans+=b[pos-1]+b[pos+1];
			for (l=pos;l<n-i+1;l++)
				b[l]=b[l+1];
			b[l]=0;}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
