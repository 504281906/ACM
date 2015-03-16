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
struct node
{
	int x,y;
}b[200005];
int a[200005];
int main()
{
	int n;
	while (~scanf("%d",&n) && n)
	{
		int ans=0,x,i;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			ans^=a[i];
		}
		if (ans==0) puts("No");
		else
		{
		int t=0;
		for (i=1;i<=n;i++)
		{
			if ((a[i]^ans)<=ans && (a[i]^ans)<=a[i])
			{
				t++;
				b[t].x=a[i];
				b[t].y=a[i]^ans;
			}
		}
		puts("Yes");
		for (i=1;i<=t;i++)
			printf("%d %d\n",b[i].x,b[i].y);
		}
	}
	return 0;
}
