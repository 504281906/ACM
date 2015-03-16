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
#define eps 1e-8
using namespace std;
struct point 
{
	double x,y;
	point (){}
	point (double x,double y):x(x),y(y){}
};
struct line
{
	point a,b;
	int t;
};
point operator -(point a,point b)
{
	return point(a.x-b.x,a.y-b.y);
}
double cross(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
int pd(point a,point b,point c,point d)
{
	double c1=cross(b-a,c-a);double c2=cross(b-a,d-a);
	double c3=cross(d-c,a-c);double c4=cross(d-c,b-c);
	return (c1*c2<=0 && c3*c4<=0);   //这里再考虑下是不是等于0 
}
line l;
int main()
{
	int n,i;
	double x1,x2,y1,y2;
	while (~scanf("%d",&n) && n)
	{
		queue<line>q[2];
		for (i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			l.a.x=x1;l.a.y=y1;
			l.b.x=x2;l.b.y=y2;
			l.t=i;
			int k=i%2;
			int k1=(k+1)%2;
			while (!q[k].empty())
			{
				line h=q[k].front();
				q[k].pop();
				if (!pd(h.a,h.b,l.a,l.b))
					q[k1].push(h);
			}
			q[k1].push(l);
		}
		int k=(n+1)%2;
		cout<<"Top sticks: "<<q[k].front().t;
		q[k].pop();
		while (!q[k].empty())
		{
			printf(", %d",q[k].front().t);
			q[k].pop();
		}
		cout<<"."<<endl;
	}
	return 0;
}
