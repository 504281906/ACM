#include <iostream>
using namespace std;
int main()
{
	int T,n,m;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		int s=(m+1)*m*(n+1)*n/4;
		printf("%d\n",s);
	}
	return 0;
}
