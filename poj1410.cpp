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
struct point {
	double x,y;
	point (){}
	point (double x,double y):x(x),y(y){}
};
struct line {
	point a,b;
	line(){}
	line(point a,point b):a(a),b(b){}
};
point p1,p2,p3,p4;
int in()
{
	if (p1.x>=p3.x && p1.x<=p4.x && p1.y>=p4.y && p1.y<=p3.y)
		return 1;
	if (p2.x>=p3.x && p2.x<=p4.x && p2.y>=p4.y && p2.y<=p3.y)
		return 1;
	return 0;
}
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
	double k1=cross(b-a,c-a),k2=cross(b-a,d-a);
	double k3=cross(d-c,a-c),k4=cross(d-c,b-c);
	if (k1*k2<eps && k3*k4<-eps) return 1;
	return 0;
}
int main()
{
	int T;
	double x1,x2,x3,x4,y1,y2,y3,y4;
	//freopen("out.txt","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if (x3>x4)
		{
			x3=x3+x4;
			x4=x3-x4;
			x3=x3-x4;
		}
		if (y3<y4)
		{
			y3=y3+y4;
			y4=y3-y4;
			y3=y3-y4;
		}
		p1=point(x1,y1);
		p2=point(x2,y2);
		p3=point(x3,y3);
		p4=point(x4,y4);
		line l1=line(p1,p2);
		line l[5];
		l[1].a=p3;l[1].b=point(x4,y3);
		l[2].a=p3;l[2].b=point(x3,y4);
		l[3].a=point(x3,y4);l[3].b=p4;
		l[4].a=p4;l[4].b=point(x4,y3);
		if (in())
		{
			cout<<"T"<<endl;
			continue;
		}
		int flag=1;
		for (int i=1;i<=4;i++)
			if (pd(p1,p2,l[i].a,l[i].b))
			{
				cout<<"T"<<endl;
				flag=0;
				break;
			}
		if (flag) cout<<"F"<<endl;
	}
	return 0;
}
