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
int a[1000010],b[10000010];
int main(){
	int T,i,n;
	scanf("%d",&T);
	while (T--){
		int ans=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[a[i]]=i;
		}
		int k=0;
		for (i=n;i>=1;i--){
			if (b[i]-k<i)ans++;
			k++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
