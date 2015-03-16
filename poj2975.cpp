#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define ll __int64
int a[1010];
int n,i;
int main()
{
	while (~scanf("%d",&n) && n)
	{
		ll ans=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			ans^=a[i];
		}
		if (!ans) printf("0\n");
		else
		{
			int t=0;
			for (i=1;i<=n;i++)
				if (a[i]>(a[i]^ans))
					t++;
			printf("%d\n",t);
		}
	}
	return 0;
}
