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
#include <ctime>
#define LL __int64
#define EPS 1e-8
using namespace std;
int main()
{
	int n,i;
	while (~scanf("%d",&n))
	{
		LL ans=0,k;
		for (i=1;i<=n;i++)
		{
			scanf("%I64d",&k);
			ans^=k;
		}
		if (ans==0) puts("Lose");
		else puts("Win");
	}
	return 0;
}
