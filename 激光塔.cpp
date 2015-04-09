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
#define LL long long
using namespace std;
struct node
{
	LL x,y;
}f[100010];
int cmp(node a,node b)
{
	if (a.x==b.x)
		return a.y<b.y;
	else return a.x<b.x;
}
int main()
{
	int n,i;
	LL a,b;
	scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		scanf("%lld%lld",&a,&b);
		f[i].x=a;
		if (b!=0)
			f[i].y=a+b-1;
		else f[i].y=a;
	}
	sort(f,f+n,cmp);
	int t=0,ans=0;
	for (i=0;i<n;i++)
	{
		if (f[i].y>=t)
		{
			ans++;
			if (f[i].x>=t) t=f[i].x+1;
			else t++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
