#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int T,n,i,k;
	scanf("%d",&T);
	while (T--)
	{
		int ans=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			if (k % 4==2 || k % 4==1)
				ans^=k;
			else if (k % 4==0)
				ans^=(k-1);
			else ans^=(k+1);
		}
		if (ans==0) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}
