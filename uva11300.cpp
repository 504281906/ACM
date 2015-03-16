#include <cstdio>
#include <algorithm>
using namespace std;
long long c[1000010];
int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		long long s=0;
		c[0]=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%lld",&c[i]);
			s+=c[i];
		}
		s=s/n;
		for (int i=1;i<n;i++)
			c[i]=c[i-1]+c[i]-s;
		sort(c,c+n);
		long long m=c[n/2];
		s=0;
		for (int i=0;i<n;i++)
			s+=abs(m-c[i]);
		printf("%lld\n",s);
	}
	return 0;
} 
