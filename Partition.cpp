#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1000000007
int ff(int x)
{
	int s=0;
	for (int i=x-2;i>=1;i--)
	s=(s+i*(i+1)) % M;
	return s;
}
int main()
{
	int T,a,b;
	scanf("%d",&T);
	while (T--)
	{
		int max=0;
		scanf("%d%d",&a,&b);
		int k=b-1;
		max=((a-k)+ff(a-k)) % M;
		printf("%d\n",max);
	}
	return 0;
}
