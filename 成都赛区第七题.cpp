#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int T;
	int f=1; 
	long long i,a,b;
	scanf("%d",&T);
	while (T--)
	{
		//printf("Case #%d: ",f++);
		long long k=0;
		long long s=0;
		int t=0;
		scanf("%lld%lld",&a,&b);
		while (a)
		{
			s+=(a%10)*(1 << t);
			t++;
			a/=10;
		}
		for (i=0;i<=b;i++)
		{
			long long s1=0;
			t=0;
			long long j=i;
			while (j)
			{
				s1+=(j%10)*(1 << t);
				t++;
				j/=10;
			}
			if (s1<=s) 
			{
				k++;
				printf("%lld ",i);
			}
		}
		printf("%lld\n",k);
	}
	return 0;
}
