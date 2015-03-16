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
#define eps 1e-9
using namespace std;
struct point{
	double x,y;
	point (){}
	point (double x,double y):x(x),y(y){}
};
struct line{
	point a,b;
};
line l[5];
point operator -(point a,point b){
	return point(a.x-b.x,a.y-b.y);
}
int dcmp(double x){
	if (fabs(x)<eps) return 0;
	else return x<0?-1:1;
}
double cross(point a,point b,point c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int segment(point a,point b,point c){ //判断C点是否在a,b线段上
	double x_min,x_max,y_min,y_max;
	if (a.x<b.x){
		x_min=a.x;x_max=b.x;
	}
	else{
		x_min=b.x;x_max=a.x;
	}
	if (a.y<b.y){
		y_min=a.y;y_max=b.y;
	}
	else{
		y_min=b.y;y_max=a.y;
	}
	if (c.x<x_min || c.x>x_max || c.y<y_min || c.y>y_max)
		return 0;
	else return 1;
} 
int go(line l1,line l2){
	double k1=cross(l1.a,l1.b,l2.a);
	double k2=cross(l1.a,l1.b,l2.b);
	double k3=cross(l2.a,l2.b,l1.a);
	double k4=cross(l2.a,l2.b,l1.b);
	if (dcmp(k1*k2)<0 && dcmp(k3*k4)<0) return 1;
	if (dcmp(k1)==0 && segment(l1.a,l1.b,l2.a))
		return 1;
	if (dcmp(k2)==0 && segment(l1.a,l1.b,l2.b))
		return 1;
	if (dcmp(k3)==0 && segment(l2.a,l2.b,l1.a))
		return 1;
	if (dcmp(k4)==0 && segment(l2.a,l2.b,l1.b))
		return 1;
	return 0;
}
int main(){
	while (~scanf("%lf%lf%lf%lf",&l[1].a.x,&l[1].a.y,&l[1].b.x,&l[1].b.y)){
		scanf("%lf%lf%lf%lf",&l[2].a.x,&l[2].a.y,&l[2].b.x,&l[2].b.y);
		if (go(l[1],l[2]))
			cout<<"这两条线段相交"<<endl;
		else cout<<"这两条线段不想交"<<endl;		
	}
	return 0;
}
