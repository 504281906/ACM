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
#define LL __int64
#define EPS 1e-8
using namespace std;
int hs[100010],hs1[100010],a[100010],ans[100010][2];
int main()
{
	int n,i,j;
	while (~scanf("%d",&n) && n)
	{
		memset(hs,0,sizeof(hs));
		memset(hs1,0,sizeof(hs));
		memset(ans,0,sizeof(ans));
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			int p=sqrt(a[i]);
			for (j=1;j<=p;j++)
			{
				if (a[i] % j==0)
				{
					if (!ans[hs[j]][0])
						ans[hs[j]][0]=a[i];
					if (!ans[hs[a[i]/j]][0])
						ans[hs[a[i]/j]][0]=a[i];
				}
			}
			hs[a[i]]=i;
		}
		for (i=n;i>=1;i--)
		{
			int p=sqrt(a[i]);
			for (j=1;j<=p;j++)
			{
				if (a[i] % j==0)
				{
					if (!ans[hs1[j]][1])
						ans[hs1[j]][1]=a[i];
					if (!ans[hs1[a[i]/j]][1])
						ans[hs1[a[i]/j]][1]=a[i];
				}
			}
			hs1[a[i]]=i;
		}
		LL s=0;
		for (i=1;i<=n;i++)
		{
			for (j=0;j<=1;j++)
				if (!ans[i][j])
					ans[i][j]=a[i];
			s+=1LL*ans[i][0]*ans[i][1];
		}
		cout<<s<<endl;
	}
	return 0;
}
