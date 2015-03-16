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
int a[110],b[110];
int main(){
	int n,m,i,j;
	scanf("%d",&n);
	for (i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for (i=0;i<m;i++)
		scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
	i=0;j=0;
	int ans=0;
	while (i<n && j<m){
		if (fabs(a[i]-b[j])<=1){
			ans++;
			i++;
			j++;
		}
		else
		if (a[i]>b[j]) j++;
		else i++;
	}
	cout<<ans<<endl;
	return 0;
}
