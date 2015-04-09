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
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
int a[1010],T,n,i,j,m,b,f[1010];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
			scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		int mx=0;
		int ans=0;
		scanf("%d",&m);
		for (i=0;i<m;i++)
		{
			scanf("%d",&b);
			mx=0;
			for (j=0;j<n;j++)
			{
				if (b>a[j])
					mx=max(mx,f[j]);
				else if (b==a[j])
					f[j]=mx+1;
			}
		}
		for (i=0;i<n;i++)
			ans=max(ans,f[i]);
		cout<<ans<<endl;
	}
	return 0;
}
