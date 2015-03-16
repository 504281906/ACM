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
	int T,n,m;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		if (m&1)
		{
			if (n&1) puts("1");
			else puts("0");
		}
		else
		{
			n=n%(m+1);
			if (n==m) cout<<m<<endl;
			else
			{
				if (n&1) puts("1");
				else puts("0");
			}
		}
	}
	return 0;
}
