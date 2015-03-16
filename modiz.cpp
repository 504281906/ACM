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
	int T;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
	scanf("%d",&T);
	while (T--){
		scanf("%lf%lf",&d.x,&d.y);
		point A,B,C;
		A=a-d;
		B=b-d;
		C=c-d;
		double s,s1;
		s=cross(A,B)/2+cross(A,C)/2+cross(B,C)/2;
		s1=cross(c-b,a-b)/2;
		//cout<<s<<" "<<s1<<endl;
		if (fabs(s-s1)<EPS) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
