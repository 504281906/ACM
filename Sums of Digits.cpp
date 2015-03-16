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
LL i,j;
int n,a[400],b[400];
int main(){
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	LL h=1,m=0,k=0;
	for (i=1;i<=n;i++){
		k=m/h;
		LL ans=0;
		int s=a[i];
		if (s<=k){
			h*=10;
			m=k*h;
			b[i]=m;
		}
		else{
			ans=(k+1)*h;
			s=s-k-1;
			int flag=1;
			for (j=h/10;s!=0 && j!=0;j/=10){
				if (s>9) 
				{
					ans+=j*9;
					s-=9;
				}
				else {
					ans+=j*s;
					break;
				}
				if (j==1) break;
			}
			while (s){
				h*=10;
				if (s>9){
					ans+=9*h;
					s-=9;
				}
				else{
					ans+=s*h;
					break;
				}
			}
			m=ans;
			b[i]=m;
		}
	}
	for (i=1;i<=n;i++)
		printf("%d\n",b[i]);
	return 0;
}
