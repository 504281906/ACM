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
int a[20],Max,Min,p1,p2,n;
int gg(){
	for (int i=1;i<n;i++)
		if (a[0]!=a[i]) return 1;
	return 0;
}
void find(){
	Max=a[0];
	Min=a[0];
	p1=0;
	p2=0;
	for (int i=1;i<n;i++){
		if (Max<a[i]){
			p2=i;
			Max=a[i];
		}
		if (Min>a[i]){
			p1=i;
			Min=a[i];
		}
	}
}
int main(){
	int T,i;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		while (gg()){
			find();
			int s=Max-Min;
			a[p1]=s;
			a[p2]=s;
		}
		printf("%d\n",a[0]);
	}
	return 0;
}
