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
	//point (){}
	point (double x=0,double y=0):x(x),y(y){}
};
struct line
{
	point a,b;
};
double cross(point a,point b)
{
	return (a.x*b.y)-(a.y*b.x);
}
point operator - (point a,point b)
{
	return point(a.x-b.x,a.y-b.y);
}
void getp(point a,point b,point c,point d)
{
	point ans;
	ans.x = ( c.x*cross(b-a,d-a) - d.x*cross(b-a,c-a) )/( cross(b-a,d-a) - cross(b-a,c-a) );
    ans.y = ( c.y*cross(b-a,d-a) - d.y*cross(b-a,c-a) )/( cross(b-a,d-a) - cross(b-a,c-a) );
    printf("POINT %.2lf %.2lf\n",ans.x,ans.y);
}
line p1,p2;
int main()
{
	int T;
	scanf("%d",&T);
	cout<<"INTERSECTING LINES OUTPUT"<<endl;
	while (T--)
	{
		scanf("%lf%lf%lf%lf",&p1.a.x,&p1.a.y,&p1.b.x,&p1.b.y);
		scanf("%lf%lf%lf%lf",&p2.a.x,&p2.a.y,&p2.b.x,&p2.b.y);
		if (cross(p1.b-p1.a,p2.b-p2.a)==0)
		{
			if (cross(p1.a-p2.a,p1.b-p2.a)==0 && cross(p1.a-p2.b,p1.b-p2.b)==0)
				cout<<"LINE"<<endl;
			else cout<<"NONE"<<endl;
		}
		else getp(p1.a,p1.b,p2.a,p2.b);
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}
