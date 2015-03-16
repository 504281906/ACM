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
int vis[50010];
struct node
{
	LL x,y;
}a[50010];
struct node1
{
	LL x,y,z;
}b[50010];
int cmp(node a,node b)
{
	return a.y+a.x>b.x+b.y;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	LL s=0;
	for (i=1;i<=n;i++)
	{
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
		s+=a[i].x;
	}
	sort(a+1,a+1+n,cmp);
	LL ans=-0x7fffffff;
	for (i=1;i<=n;i++)
	{
		LL k=s-a[i].x-a[i].y;
		if (ans<k) ans=k;
		s-=a[i].x;
	}
	cout<<ans<<endl;
	return 0;
}
