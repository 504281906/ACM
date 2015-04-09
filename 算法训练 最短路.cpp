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
#define max 10010
int a[20010][20010];
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int n,m,i,j,u,v,l;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			a[i][j]=max;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&l);
		if (a[u][v]>l)
			a[u][v]=l;
	}
	while (1)
	{
		int t = 1;
		for (i=2;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				if (a[1][i]>a[1][j]+a[j][i])
				{
					t=0;
					a[1][i]=a[1][j]+a[j][i];
				}
			}
		}
		if (t) break;
	}
	for (i=2;i<=n;i++)
		printf("%d\n",a[1][i]);
	return 0;
}
