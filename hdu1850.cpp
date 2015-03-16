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
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	int m,i;
	int a[110];
	while (scanf("%d",&m)==1 && m)
	{
		int s=0,ans=0;
		for (i=1;i<=m;i++)
		{
			scanf("%d",&a[i]);
			s=s^a[i];
		}
		for (i=1;i<=m;i++)
			if (a[i]>(s^a[i])) ans++;
		printf("%d\n",ans);
	}
	return 0;
}

