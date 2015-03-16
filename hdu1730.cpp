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
	int n,m,i,x,y;
	while (~scanf("%d%d",&n,&m))
	{
		int ans=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			ans^=(int)fabs(x-y)-1;
		}
		if (ans==0) puts("BAD LUCK!");
		else puts("I WIN!");
	} 
	return 0;
}

