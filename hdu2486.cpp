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
#define LL __int64
int T,n,k,a[2000010],b[2000010];
int main()
{
	scanf("%d",&T);
	int t=0;
	while (T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int i=0,j=0;
		a[i]=b[i]=1;
		scanf("%d%d",&n,&k);
		while (a[i]<n)
		{
			i++;
			a[i]=b[i-1]+1;
			while (a[j+1]*k<a[i])
				j++;
			if (a[j]*k<a[i])
				b[i]=b[j]+a[i];
			else b[i]=a[i];
		}
		int ans;
		printf("Case %d: ",++t);
		if (n==a[i]) puts("lose");
		else
		{
			while (n)
			{
				if (n>=a[i])
				{
					n-=a[i];
					ans=a[i];
				}
				i--;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
