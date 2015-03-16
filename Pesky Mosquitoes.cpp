#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#define eps 1e-9
#include<vector>
#define pi acos(-1)
using namespace std;
const double PI = acos(-1.0);
int dcmp( double x ){ if( fabs(x) < eps ) return 0;else return x < 0?-1:1; }
struct point{
    double x,y;
    point( double x = 0,double y = 0 ):x(x),y(y){}
}node[112]; 
typedef point Vector;
struct segment
{
    point a,b;
	segment(){}
    segment(point _a,point _b){a=_a,b=_b;}
};
struct circle{
    point c; double r;  circle(){}
    circle(point _c, double _r):c(_c),r(_r) {}
    point  PPP(double a)const{return point(c.x+cos(a)*r,c.y+sin(a)*r);}
};
struct line{
    point p,v; double ang;
    line() {}
    line( const point &_p, const point &_v):p(_p),v(_v){ang = atan2(v.y, v.x);}
    inline bool operator < (const line &L)const{return  ang < L.ang;}
};
point operator + (point a,point b){return point( a.x + b.x,a.y + b.y );}
point operator - (point a,point b){return point( a.x - b.x,a.y - b.y );}
point operator * (point a,double b){return point( a.x*b,a.y*b );}
point operator / (point a,double b){ return point( a.x/b,a.y/b );}
bool  operator <  (const point &a, const point &b ){return  a.x <  b.x || (a.x == b.x && a.y < b.y );}
bool  operator == (const point &a, const point &b ){return (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0 );}
bool  operator != (const point &a,const point &b ){return a == b?false:true;}

double Dot( point a,point b ){return a.x*b.x + a.y*b.y;} // 点到点的距离  //点积 ab=|a||b|cos@
double Length( point a ){return sqrt( Dot( a,a ) );}    // 向量长度
double Angle( point a,point b ){ return acos( Dot(a,b)/Length(a)/Length(b) );} // 两个向量的角度
double D_T_D(const double deg){ return deg/180.0*PI;}  //弧度转换成角度 
double dist(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
// 向量旋转 rad 度数 rad>0逆时针，rad<0顺时针
point Rotate( point a, double rad ){
     return point( a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad) );
}
// 向量的 法线向量 的单位向量 ==向量逆时针旋转90度
point Normal( point a ){
     double L = Length(a); 
	 return point(-a.y/L,a.x/L);
}
// 叉积计算   a*b=|a||b|sin@;
double Cross( point a,point b ){
    return a.x*b.y - a.y*b.x;
}

//已知圆上亮点求圆心 
point get_cc(point p1,point p2,double r){
    point mid=point((p1.x+p2.x)/2,(p1.y+p2.y)/2);
    double angle=atan2(p1.x-p2.x,p2.y-p1.y);
    double d=sqrt(r*r-(dist(p1,mid)*dist(p1,mid)));
    return point(mid.x+d*cos(angle),mid.y+d*sin(angle));
}
point p[50];
int main(){
	int T,n,i,j,k;
	double r;
	scanf("%d",&T);
	while (T--){
		scanf("%d%lf",&n,&r);
		r=r*1.0/2;
		for (i=1;i<=n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		int ans=0;
		for (i=1;i<n;i++)
			for (j=i+1;j<=n;j++){
				int s=0;
				point g=get_cc(p[i],p[j],r);
				for (k=1;k<=n;k++)
					if (dist(g,p[k])<=r) s++;
				if (ans<s) ans=s;
			}
		printf("%d\n",ans);
	}
}
