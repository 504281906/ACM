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
struct point
{
	double x,y;
	point (double x=0,double y=0):x(x),y(y){}
}a,b,c,d;
point operator - (point a,point b)
{
	return point(a.x-b.x,a.y-b.y);
}
double cross(point a,point b)
{
	return fabs(a.x*b.y-a.y*b.x);
}
int main()
{
	begin:
	printf("请输入三角形的三个顶点坐标:\n");
	scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	printf("请输入要判断的点的坐标，如若想重新输入三角形顶点，请输入0 0\n");
	while (~scanf("%lf%lf",&d.x,&d.y))
	{
		if (fabs(d.x)<=EPS && fabs(d.y)<=EPS)
			goto begin;
		point A,B,C;
		A=a-d;
		B=b-d;
		C=c-d;
		double s,s1;
		s=cross(A,B)/2+cross(A,C)/2+cross(B,C)/2;
		s1=cross(c-b,a-b)/2;
		//cout<<s<<" "<<s1<<endl;
		if (fabs(s-s1)<EPS) printf("此点(%lf,%lf)在三角形内\n",d.x,d.y);
		else printf("此点(%lf,%lf)不在三角形内\n",d.x,d.y);
	}
	return 0;
}
