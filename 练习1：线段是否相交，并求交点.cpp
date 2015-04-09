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
	double x,y;
	node (){}
	node (double a,double b):x(a),y(b){
	}
}p[5];
double js(node p1,node p2,node p3)
{
	node h1,h2;
	h1.x=p3.x-p1.x;
	h1.y=p3.y-p1.y;
	h2.x=p2.x-p1.x;
	h2.y=p2.y-p1.y;
	return (h1.x*h2.y-h1.y*h2.x);
}
int pd1(node p1,node p2,node p3)
{
	double t;
	if (p1.x>p2.x)
	{
		t=p1.x;
		p1.x=p2.x;
		p2.x=t;
	}
	if (p1.y>p2.y)
	{
		t=p1.y;
		p1.y=p2.y;
		p2.y=t;
	}
	if (p3.x>=p1.x && p3.x<=p2.x && p3.y>=p1.y && p3.y<=p2.y)
		return 1;
	else return 0;
}
int pd(node p1,node p2,node p3,node p4)
{
	double d1,d2,d3,d4;
	d1=js(p3,p4,p1);
	d2=js(p3,p4,p2);
	d3=js(p1,p2,p3);
	d4=js(p1,p2,p4);
	if (d1*d2<0 && d3*d4<0)
		return 1;
	else
	{
		if (d1==0 && pd1(p3,p4,p1)) return 1;
		if (d2==0 && pd1(p3,p4,p1)) return 1;
		if (d3==0 && pd1(p1,p2,p3)) return 1;
		if (d4==0 && pd1(p1,p2,p4)) return 1;
	}
	return 0;
}
node operator -(node a,node b)
{
	return node(a.x-b.x,a.y-b.y);
}
double cross(node a,node b)
{
	return (a.x*b.y)-(a.y*b.x);
}
void getp(node a,node b,node c,node d)
{
	node pp;
	pp.x=(c.x*cross(b-a,d-a)-d.x*cross(b-a,c-a))/((cross(b-a,d-a)-cross(b-a,c-a)));
	pp.y=(c.y*cross(b-a,d-a)-d.y*cross(b-a,c-a))/((cross(b-a,d-a)-cross(b-a,c-a)));
	printf("交点为:(%lf,%lf)\n",pp.x,pp.y);
	return;
}
int main()
{
	while (~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y,&p[4].x,&p[4].y))
	{
		if (pd(p[1],p[2],p[3],p[4]))
		{
			/*double t=(double)((p[1].x-p[3].x) * (p[3].y-p[4].y)-(p[1].y-p[3].y)*(p[3].x-p[4].x))
			/(double)((p[1].x-p[2].x) * (p[3].y-p[4].y)-(p[1].y-p[2].y)*(p[3].x-p[4].x));
			node q;
			q.x=(p[2].x-p[1].x)*t;
			q.y=(p[2].y-p[1].y)*t;
			printf("交点为:(%lf,%lf)\n",q.x,q.y);
			double lll=js(p[1],p[2],p[4]);
			cout<<lll<<endl;
			double k1=fabs(js(p[1],p[2],p[3])/js(p[1],p[2],p[4]));
			printf("交点为:(%lf,%lf)\n",(p[3].x+k1*p[4].x)/(1+k1),(p[3].y+k1*p[4].y)/(1+k1));*/
			getp(p[1],p[2],p[3],p[4]);
		}
		else printf("No\n");
	}
	return 0;
}
