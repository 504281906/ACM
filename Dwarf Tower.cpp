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
	int v,x,y;
}b[100010];
int a[10010];
int main()
{
	int i,n,m,f;
	scanf("%d%d",&n,&m);
		f=0;
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=1;i<=m;i++)
		{
			int k,x,y;
			scanf("%d%d%d",&k,&x,&y);
			if (a[k]>a[x]+a[y])
				a[k]=a[x]+a[y];
			b[i].x=x;
			b[i].y=y;
			b[i].v=k;
			if (k==1) f=1;
		}
		int t=1;
		while (t && f)
		{
			t=0;
			for (i=1;i<=m;i++)
				if (a[b[i].v]>a[b[i].x]+a[b[i].y])
				{
					t=1;
					a[b[i].v]=a[b[i].x]+a[b[i].y];
				}
		}
		printf("%d\n",a[1]);
	return 0;
}
