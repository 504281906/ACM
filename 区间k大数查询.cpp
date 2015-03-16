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
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,i,l,r,k,m;
	int a[1010],f[1010];
	while(~scanf("%d",&n))
	{
		for (i=1;i<=n;i++)
			scanf("%d",&f[i]);
		scanf("%d",&m);
		while (m--)
		{
			scanf("%d%d%d",&l,&r,&k);
			for (i=0;i<r-l+1;i++)
				a[i]=f[i+l];
			sort(a,a+r-l+1,cmp);
			printf("%d\n",a[k-1]);
		}
	}
	return 0;
}
