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
int main(){
	int T,a,b,i;
	scanf("%d",&T);
	while (T--){
		int ans=0;
		scanf("%d%d",&a,&b);
		if (a>b){
			a=a+b;
			b=a-b;
			a=a-b;
		}
		int g=a;
		int t=0;
		int s=1;
		for (i=1;g>=s;i++){
			g-=s;
			s*=2;
			t++;
		}
		ans=(s-1)*2+1+g;
		b=b-(s-1);
		int k=s;
		while (b&&k){
			ans++;
			b--;
			k--;
		}
		k=s+g;
		s*=2;
		while(b){
			if (b>=s){
				ans+=k;
				b-=s;
			}
			else {
				if (b+k>s) ans=ans+(b+k-s);
				break;
			}
			s*=2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
