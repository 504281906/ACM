#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double esp = 1e-8;
const double Pi = acos(-1);
int sign(double x) { return x<-esp?-1:(x>esp);}
struct Point
{
	double x, y;
	Point(){}
	Point(double _x, double _y)
	{
		x = _x; y = _y;		
	}
	Point operator - (const Point &b)const{
		return Point(x-b.x,y-b.y);	
	}
	double operator * (const Point &b)const{
		return x*b.y - b.x*y;	
	}
	double operator & (const Point &b)const{
		return x*b.x + y*b.y;	
	}	
};
double dist(Point a, Point b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) ); 
} 
double Ptoline(Point a,Point s,Point e){
	if( sign( (e-s)&(a-s) ) < 0 || sign((s-e)&(a-e)) < 0 )
		return min( dist(a,s), dist(a,e) );
	return fabs( (s-a)*(e-a) ) / dist(s,e) ;
} 

struct Line
{
	Point s, e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s = _s; e = _e;
	}
}L[4];

Point S;

double kao(double k, double x0, double y0, double r){
	double rid = k; //(k/3600000.0)*2.*Pi;	
	double x = x0 + r*sin(rid);
	double y = y0 + r*cos(rid);
	Point t = Point(x,y);
	double res = Ptoline( t, L[0].s, L[0].e );
	for(int i = 1; i < 4; i++){
		res = min( res, Ptoline( t, L[i].s, L[i].e ) );	
	}
	res += dist( t, S );		
	return res;
}
double solve(double x0, double y0, double R){
//	double l = 0, r = 3600000.0;
	double l = 0, r = 2*Pi;	
	while( r-l > 1e-6 ){
		double m1 = l+(r-l)/3.0, m2 = m1+(r-l)/3.0;
		double d1 = kao(m1,x0,y0,R), d2 = kao(m2,x0,y0,R);
		if( sign(d1-d2) <= 0 ) r = m2;
		else l = m1;
	}	
//	printf("l = %lf\n", l );
	return kao( l, x0, y0, R );	
}
int main(){
	double x, y, x1, y1, x2, y2;
	while( scanf("%lf%lf", &x,&y) != EOF){
		if( sign(x)==0 && sign(y)==0 ) break;
		S = Point(x,y);	
		double x0, y0, r;
		scanf("%lf%lf%lf", &x0,&y0,&r);
		scanf("%lf%lf%lf%lf", &x1,&y1,&x2,&y2);
		double xmax, xmin, ymax, ymin;
		xmax = max( x1, x2 ); xmin = min( x1, x2 );
		ymax = max( y1, y2 ); ymin = min( y1, y2 );
		L[0] = Line( Point(xmin,ymin), Point(xmin,ymax) );
		L[1] = Line( Point(xmin,ymin), Point(xmax,ymin) );
		L[2] = Line( Point(xmin,ymax), Point(xmax,ymax) );
		L[3] = Line( Point(xmax,ymin), Point(xmax,ymax) );
		double ans = solve( x0, y0, r );	
		printf("%.2lf\n", ans );	
	}
	return 0;
}

