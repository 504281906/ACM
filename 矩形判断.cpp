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
#define LL long long
#define EPS 1e-8
using namespace std;
LL dis(LL x1,LL y1,LL x2,LL y2)
{
	return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
struct node
{
	LL x1,y1,x2,y2;
}p[5];
struct node1
{
	LL x,y;
}g[20];
int main()
{
	int T,i,j;
	scanf("%d",&T);
 	while (T--)
	{
		map< pair<LL , LL> ,int>mp;
		pair<LL,LL>t;
		LL d[4];
		int flag=0;
		int h=0;
		for (i=1;i<=4;i++)
		{
			scanf("%lld %lld %lld %lld",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
			d[i-1]=dis(p[i].x1,p[i].y1,p[i].x2,p[i].y2);
			int ff=1;
			t=make_pair(p[i].x1,p[i].y1);
			if (mp[t]==0)
			{
				ff=0;
				g[h].x=p[i].x1;
				g[h].y=p[i].y1;
				h++;
			}
			mp[t]++;
			if (mp[t]>2) flag=1;
			t=make_pair(p[i].x2,p[i].y2);
			if (mp[t]==0)
			{
				ff=0;
				g[h].x=p[i].x2;
				g[h].y=p[i].y2;
				h++;
			}
			mp[t]++;
			if (mp[t]>2) flag=1;
			if (ff && h!=4) flag=1;
		}
		if (h!=4 || flag) 
		{
			puts("NO");
			continue;
		}
		sort(d,d+4);
		if (d[0]==0 || d[0]!=d[1]  || d[2]!=d[3])
		{
			puts("NO");
			continue;
		}
		LL q[3];
		flag=1;
		for (i=1;i<=2;i++)
		if (flag)
			for (j=i+1;j<=3;j++)
			{
				q[0]=dis(g[0].x,g[0].y,g[i].x,g[i].y);
				q[1]=dis(g[0].x,g[0].y,g[j].x,g[j].y);
				q[2]=dis(g[j].x,g[j].y,g[i].x,g[i].y);
				sort(q,q+3);
				if (q[0]+q[1]!=q[2])
				{
					flag=0;
					break;
				}
			}
		if (flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
