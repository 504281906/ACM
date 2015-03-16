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
int a[500];
int main()
{
	int i,p,n;
	scanf("%d%d",&p,&n);
		memset(a,0,sizeof(a));
		for (i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			x= x % p;
			if (a[x])
			{
				printf("%d\n",i);
				break;
			}
			a[x]=1;
		}
		if (i==n+1) printf("-1\n");
	return 0;
}
