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
	int s,kf,km,jf,jm;
}a[110];
struct node1
{
	int x,y,z;
}b[110];
int cmp(node1 a,node1 b)
{
	if (a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	int T,i,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
		{
			scanf("%d %d:%d %d:%d",&a[i].s,&a[i].kf,&a[i].km,&a[i].jf,&a[i].jm);
			b[i].z=a[i].s;
			b[i].x=a[i].kf*60+a[i].km;
			b[i].y=a[i].jf*60+a[i].jm;
		}
		sort(b+1,b+1+n,cmp);
		int k=b[1].z,ans=b[1].z,y=b[1].y;
		for (i=2;i<=n;i++)
		{
			if (b[i].x>=y)
			{
				y=b[i].y;
				k=b[i].z;
				if (k>ans) ans=k;
			}
			else
			{
				k+=b[i].z;
				if (b[i].y>y)
					y=b[i].y;
				if (k>ans) ans=k;
			}
		}
		if (k>ans) ans=k;
		cout<<ans<<endl;
	}
	return 0;
}

