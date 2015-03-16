#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int f[20010],k[20010];
int main()
{
	int n,m,i;
	while (~scanf("%d%d",&n,&m))
	{
		map<int,int>map;
		map.clear();
		int ans=0,ff=0;
		memset(f,0,sizeof(f));
		for (i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if (map[b]==1 && f[a]==0)
				ff++;
			if (f[a]==1 && map[b]==1)
				ans++;
			if (f[a]==0)
			{
				ans++;
				f[a]=1;
			}
			//if (map[a]==1 && f[b]==1)
			//	ans--;
			map[b]=1;
			map[a]=1;
		}
		if (n==1)
		{
			printf("0\n");
			continue;
		}
		printf("%d\n",n-ans+ff);
	}
	return 0;
}
