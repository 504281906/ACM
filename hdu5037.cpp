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
#define EPS 1e-8
using namespace std;
int a[200010];
int main()
{
	int T,i,n,m,l,cas=1;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&l);
		for (i=0;i<n;i++)
			scanf("%d",a+i);
		a[n]=m;
		sort(a,a+n+1);
		int step=l,pos=0,ans=0;
		for (i=0;i<=n;i++)
		{
			int s=a[i]-pos;
			if (s==0) continue;
			if (s+step<=l)
			{
				pos=a[i];
				step+=s;
			}
			else
				if (s<=l)
				{
					ans++;
					step=s;
					pos=a[i];
				}
				else
				{
					int k=s % (l+1);
					ans+=(s/(l+1))*2;
					if (k+step<=l)
					{
						pos=a[i];
						step+=k;
					}
					else
					{
						ans++;
						pos=a[i];
						step=k;
					}
				}
		}
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}
