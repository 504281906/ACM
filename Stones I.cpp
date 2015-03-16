#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
using namespace std;
//#define DEBUG
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int a[1010],b[1010],c[1010],n,i,j;
	while (~scanf("%d",&n)&&n)
	{
		for (i=0;i<n;i++)
			scanf("%d%d",&a[i],&b[i]);
		int ans=-0x7fffffff;
		for (i=1;i<=n;i++)
		{
			for (j=0;j<n;j++)
				c[j]=a[j]-i*b[j];
			sort(c,c+n,cmp);
			int sum=0;
			for (j=0;j<i;j++)
				sum+=c[j];
			ans=max(ans,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}
