#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int a[10010],T,n,i;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		a[0]=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		for (i=n;i>0;i-=2)
			ans^=(a[i]-a[i-1]-1);
		if (!ans) printf("Bob will win\n");
		else printf("Georgia will win\n");
	}
	return 0;
}
