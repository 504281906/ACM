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
	int T,n,i,x;
	while(~scanf("%d",&n))
	{
		int ans=0,t=0;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans^=x;
			if (x>1) t=1;
		}
		if (t==0)
		{
			if (n & 1) puts("No");
			else puts("Yes");
		} 
		else if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}
