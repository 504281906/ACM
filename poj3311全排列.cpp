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
int mp[15][15];
int a[15],n,i,j,k;
int main()
{
	while(1==scanf("%d",&n)&&n) 
	{
		for (i=0;i<=n;i++)
		{
			if (i!=0) a[i-1]=i;
			for (j=0;j<=n;j++)
				scanf("%d",&mp[i][j]);
		}
		for (k=0;k<=n;k++)
		for (i=0;i<=n;i++)
		for (j=0;j<=n;j++)
		if (mp[i][k]+mp[k][j]<mp[i][j])
			mp[i][j]=mp[i][k]+mp[k][j];
		sort(a,a+n);
		int ans=0x7fffffff;
		do
		{
			int sum=mp[0][a[0]];
			for (i=1;i<n;i++)
				sum+=mp[a[i-1]][a[i]];
			sum+=mp[a[n-1]][0];
			if (sum<ans)
				ans=sum;
		}while (next_permutation(a,a+n));
		cout<<ans<<endl;
	}
	return 0;
}
