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
int main(){
	LL n; 
	while (~scanf("%lld",&n)){
		LL ans1=n*(n+1)*(2*n+1)/6;//1的平方加到n的平方 
		LL ans2=(n*(n+1)/2)*(n*(n+1)/2);////1的立方加到n的立方 
		printf("%lld %lld\n",ans1,ans2); 
	}
	return 0;
}
