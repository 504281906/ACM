#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	long long a,b,c,k;
	int i;
	while (~scanf("%lld%lld%lld%lld",&a,&b,&c,&k) && (a+b+c+k))
	{
		map<long long,int>mp;
		mp.clear();
		int t=0;
		long long s=1;
		for (i=1;i<=k;i++)
			s*=2;
		while (a!=b && mp[a]==0)
		{
			mp[a]=1;
			a=(a+c) % s;
			t++;
		}
		if (mp[a]==0) cout<<t<<endl;
			else printf("FOREVER\n");
	}
	return 0;
}

