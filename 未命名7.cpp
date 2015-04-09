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
	int ans=min(a,b);
	ans=min(ans,(a+b)/3);
	cout<<ans<<endl;
	return 0;
}
