#include <cstdio>
int main()
{
	int T,i,k,n;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		int ans=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&k);
			if ( (i % 2==0 && i % 3==0) || (i%3==2) )
				ans^=k;
		}
		if (ans) printf("Case %d: Alice\n",t);
		else printf("Case %d: Bob\n",t);
	}
	return 0;
}
