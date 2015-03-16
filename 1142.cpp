#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#ifdef WINDOWS
	#define LL __int64
	#define LLD "%I64d"
#else
	#define LL long long
	#define LLD "%lld"
#endif

const int max_n = 1004;
const LL INF = 0x3fffffff;
int n, m;
struct point
{
	int x, y;
};

int map[max_n][max_n];
LL vis[max_n], dis[max_n];
LL s[max_n];

LL DFS(int p)
{
	if (p==2)
	{
		return 1;
	}
	if (s[p] > 0)
	{
		//s[2]+=s[p];
		return s[p];
	}
	for (int i = 2; i <= n; i ++)
	{
		if ((dis[i] < dis[p] || i==2) && map[p][i] < INF)
			s[p] += DFS(i);
			
	}
	return s[p];
}

int main ()
{
	while (~scanf ("%d", &n) && n)
	{
		scanf ("%d", &m);
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				map[i][j] = INF;
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf ("%d%d%d", &a, &b, &c);
			map[a][b] = map[b][a] = c;
		}
		memset(vis, 0, sizeof (vis));
		memset(s, 0, sizeof(s));
		for (int i = 1; i <= n; i ++)
		{
			dis[i] = map[2][i];
		}
		vis[2] = 1;
		for (int i = 0; i < n; i ++)
		{
			int k;
			LL min = INF;
			for (int j = 1; j <= n; j ++)
			{
				if (!vis[j] && min > dis[j])
				{
					min = dis[j];
					k = j;
				}
			}
			vis[k] = 1;
			for (int j = 1; j <= n; j ++)
			{
				if (!vis[j] && dis[j] > dis[k] + map[k][j])
					dis[j] = dis[k] + map[k][j];
			}
		}
		for (int i = 1; i <= n; i ++)
		//{
			cout << i <<" " <<dis[i] <<endl;
	//	}
		DFS(1);
		printf (LLD"\n", s[1]);
	}
	return 0;
}
