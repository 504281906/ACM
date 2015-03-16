#include <cstdio>
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		int ans=0;
		for (i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			ans^=k;
		}
		if (ans==0) puts("No");
		else puts("Yes");
	}
	return 0;
}
