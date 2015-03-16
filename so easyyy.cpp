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
LL a,b,n,m;
LL go(){
	LL x=1,y=0,t1=a,t2=1;
	LL tt;
	while (n){
		if (n & 1){
			tt=x;
			x=(x*t1+y*t2*b)%m;
			y=(tt*t2+y*t1)%m;
		}
		tt=t1;
		t1=(t1*t1+t2*t2*b)%m;
		t2=(tt*2*t2)%m;
		n>>=1;
	}
	return (x*2)%m;
}
int main(){
	while (~scanf("%lld%lld%lld%lld",&a,&b,&n,&m)){
		cout<<go()<<endl;
	}
	return 0;
}
