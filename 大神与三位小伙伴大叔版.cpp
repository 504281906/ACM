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
const int mod=1e9+7;
int main()
{
	int T,cas;
	long long t1,t2,t,ans,n;
	scanf("%d",&T);
	for (cas=1;cas<=T;cas++)
	{
		scanf("%lld",&n);
		if (n&1)
		{
			t1=n%mod;
			t2=(n+1)/2%mod;
		}
		else
		{
			t1=(n+1)/2%mod;
			t2=n%mod;
		}
		t=t1*t2%mod;
		ans=t*t%mod*t%mod;
		ans=ans-t*t%mod*2%mod*(n-1)%mod;
		printf("Case #%d: %lld\n",cas,ans);	
	}
	return 0;
}

