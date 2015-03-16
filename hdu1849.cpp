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
int main()
{
	int n;
	while (~scanf("%d",&n) && n)
	{
		int ans=0,i;
		for (i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			ans^=x;
		}
		if (ans) puts("Rabbit Win!");
		else puts("Grass Win!");
	}
	return 0;
}

