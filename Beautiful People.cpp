#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct node 
{
	int id;
	int s,b;
}a[100010];
int dp[100010],f[100010];
bool cmp(node x,node y)
{
	if (x.s==y.s)
		return x.b>y.b;
	return x.s<y.s;
}
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			a[i].id=i;
			scanf("%d%d",&a[i].s,&a[i].b);
		}
		sort(a+1,a+n+1,cmp);
		dp[1]=1;
		int k=1;
		for (i=2;i<=n;i++)
		{
				if (a[i].b>a[dp[k]].b)
				{
					dp[++k]=i;
					f[i]=dp[k-1];
				}
				else
				{
					int low=1,high=k,mid;
					while (low<high)
					{
						mid=(low+high)/2;
						if (a[i].b>a[dp[mid]].b) low=mid+1;
										else high=mid;
					}
					dp[low]=i;
					f[i]=dp[low-1];
				}
		}
		printf("%d\n",k);
		int l=dp[k--];
		printf("%d",a[l].id);
		while (k--)
		{
			l=f[l];
			printf(" %d",a[l].id);
		}
		printf("\n");
		if (T) printf("\n");
	} 
	return 0;
}
