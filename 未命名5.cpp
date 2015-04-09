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
int a[100010],b[100010],c[100010];
int main(){
	int n,i;
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for (i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (i=1;i<n;i++)
		scanf("%d",&b[i]);
	sort(b+1,b+n);
	for (i=1;i<n-1;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+n-1);
	int ans1=0,ans2=0;
	for (i=1;i<=n;i++)
		if (a[i]!=b[i]){
			ans1=a[i];
			break;
		}
	for (i=1;i<n;i++)
		if (b[i]!=c[i]){
			ans2=b[i];
			break;
		}
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}

