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
using namespace std;
#define LL __int64
int main()
{
	LL n,m,k,ans;
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if ((n-1)+(m-1)<k) 
	{
		printf("-1\n");
		return 0;
	}
	ans=0;
	for (int i=1;i<=n;i++)
	{
		
		int h=n/(n/i);
		i=h;
		if (m-1<(k-i+1)) continue;
		LL l=max(k-i+2,1LL);
		ans=max(ans,(n/i*(m/l))) ;
	}
	printf("%I64d\n",ans);
	return 0;
}
