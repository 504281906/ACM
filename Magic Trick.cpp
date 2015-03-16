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
#define m 4
int main()
{
	freopen("A-small-attempt3.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int n,n1,i,j,T,cas=1;
	int a[5][5];
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		map<int,int>mp;
		for (i=1;i<=m;i++)
			for (j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for (i=1;i<=m;i++)
			mp[a[n][i]]=1;
		scanf("%d",&n1);
		for (i=1;i<=m;i++)
			for (j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		int t=0,s;
		for (i=1;i<=m;i++)
			if (mp[a[n1][i]]) 
			{
				t++;
				s=a[n1][i];
			}
		if (t>1) printf("Case #%d: Bad magician!\n",cas++);
		else if (t==0) printf("Case #%d: Volunteer cheated!\n",cas++);
		else printf("Case #%d: %d\n",cas++,s);
		mp.clear();
	}
	return 0;
}
