#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct node 
{
	int x,y,l;
}v[510];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mp[a[i]]=1;
		}
		for (i=1;i<=m;i++)
			scanf("%d%d%d",&v[i].x,&v[i].y,&v[i].l);
		for (i=1;i<=m;i++)
		{
			if (mp[i]) t[i]=0;
		}
	}
	return 0;
}

