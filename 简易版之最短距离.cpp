#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int T,i,n,a[10010];
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int k=a[(n+1)/2];
		int s=0;
		for (i=1;i<=n;i++)
			s+=fabs(k-a[i]);
		printf("%d\n",s);
	}
	return 0;
}
