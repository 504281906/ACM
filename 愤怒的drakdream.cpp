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
#define pi acos(-1)
using namespace std;
struct point{
	double x,y;
};
struct circle{
	point o;
	double r;
}c[5];
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double go(circle a,circle b){
	if (a.r<b.r){
		circle c;
		c=a;
		a=b;
		b=c;
	}
	double d=dis(a.o,b.o);
	if (d>=a.r+b.r) return 0;
	if (d<=a.r-b.r) return b.r*b.r*pi;
	double a1=acos((a.r*a.r+d*d-b.r*b.r)/(2*a.r*d));
	double b1=acos((b.r*b.r+d*d-a.r*a.r)/(2*b.r*d));
	double s=a1*a.r*a.r+b1*b.r*b.r;
	double s1=a.r*d*sin(a1);
	return s-s1;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%lf%lf%lf",&c[1].o.x,&c[1].o.y,&c[1].r);
		scanf("%lf%lf%lf",&c[2].o.x,&c[2].o.y,&c[2].r);
		double s=go(c[1],c[2]);
		printf("%f\n",s);
	}
	return 0;
}
