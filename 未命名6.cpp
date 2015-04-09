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
	int a,b;
	scanf("%d%d",&a,&b);
	int ans=0;
	while (a!=0 && b!=0 && (a+b>=3)){
		if (a>b){
			a=a+b;
			b=a-b;
			a=a-b;
		}
		if (a*2<=b){
			ans+=a;
			break;
		}else{
			ans+=b/2;
			b=1;
			a-=b/2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
