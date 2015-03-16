#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define M 10000000007
long long ff(int a,int b,int c)
{
	int i;
	long long s=0;
	if (a+2<b) return 0;
	if (b==0) return 1;
	if (c==1) return s+ff(a-3,b-1,1);
	for (i=1;i<c;i++)
		if (b>=i)						
			s=(s+ff(a-i-2,b-i,i)) % M;
	return s;
}
int main()
{
	int T,n,m,k;
	scanf("%d",&T);
	while (T--)
	{
		long long ss;
		scanf("%d%d%d",&n,&m,&k);
		ss=ff(n,m,k);
		printf("%lld\n",ss);		
	}
	return 0;
}
