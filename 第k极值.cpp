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
int ss(LL s){
	if (s<2) return 0;
	if (s==2) return 1;
	for (int i=2;i<=sqrt(s);i++)
		if (s % i==0) return 0;
	return 1;
}
LL a[100010];
int main(){
	int i,n,k;
	scanf("%d%d",&n,&k);
	for (i=0;i<n;i++)
		scanf("%lld",&a[i]);
	sort(a,a+n);
	LL s=a[n-k]-a[k-1]; 
	if (ss(s)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	cout<<s<<endl;
	return 0;
}
