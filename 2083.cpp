#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int a[510];
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int k=a[(n+1)/2];
		int ans=0;
		for (i=1;i<=n;i++)
			if (k>a[i]) ans+=k-a[i];
			else ans+=a[i]-k;
		printf("%d\n",ans);
	}
	return 0;
}

