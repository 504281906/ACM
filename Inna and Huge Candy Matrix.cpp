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
struct node
{
	__int64 x,y;
}a[100010];
int main()
{
#ifdef DEBUG
	freopen("cin.txt", "r", stdin);
	freopen("cout.txt", "w", stdout);
#endif
	__int64 n,m,x,y,z;
	int i,p;
	memset(a,0,sizeof(a));
	scanf("%I64d %I64d %I64d %I64d %I64d %d",&n,&m,&x,&y,&z,&p);
	for (i=1;i<=p;i++)
		scanf("%I64d %I64d",&a[i].x,&a[i].y);
	x%=4;
	while (x--)
	{
	for (i=1;i<=p;i++)
	{ 
		int xx=a[i].x;
		int yy=a[i].y;
		a[i].x=yy;
		a[i].y=n-xx+1;
	}
	int t=m;
		m=n;
		n=t;
	}
	y=y%2;
	if (y)
		for (i=1;i<=p;i++)
			a[i].y=m-a[i].y+1;
	z%=4;
	while (z--)
	{
	for (i=1;i<=p;i++)
	{
		int xx=a[i].x;
		int yy=a[i].y;
		a[i].y=xx;
		a[i].x=m-yy+1;
	}
		int t=m;
		m=n;
		n=t;
	}
	for (i=1;i<=p;i++)
		printf("%I64d %I64d\n",a[i].x,a[i].y);
	return 0;
}
