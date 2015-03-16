#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#define eps 1e-9
#include<vector>
const double INF=1e9;
using namespace std;
double d[200][200];
const double PI = acos(-1.0);
int dcmp( double x ){ if( abs(x) < eps ) return 0;else return x < 0?-1:1; }
struct point{
    double x,y;
    point( double x = 0,double y = 0 ):x(x),y(y){}
}node[112]; 
typedef point Vector;
struct segment{
    point a,b;  segment(){}
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
double D_T_D(const double &deg ){ return deg/180.0*PI; }

// 叉积计算   a*b=|a||b|sin@;
double Cross( point a,point b ){
    return a.x*b.y - a.y*b.x;
}
// 线段相交判断 先必须去掉不相交的状态；再判断方向
bool SegmentProperIntersection(const point& a1, const point& a2, const point& b1, const point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
//点pot 是否 在线段 ab 上 只需 叉积等于0  点积等于0
bool online(const point a,const point b,const point pot ){
    if( Cross( a - pot,b - pot ) == 0 && Dot( a - pot,b - pot ) <= 0 )return 1;
    return 0;
}

//p为点,poly为多边形 点在多边形内判定
int isinpoly(const point& p, const vector<point> poly){
  int n = poly.size();
  int wn = 0;
  for(int i = 0; i < n; i++){
    const point& p1 = poly[i];
    const point& p2 = poly[(i+1)%n];
    if(p1 == p || p2 == p || online(p1, p2 ,p)) return -1; 
    int k = dcmp(Cross(p2-p1, p-p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if(k > 0 && d1 <= 0 && d2 > 0) wn++;
    if(k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1; //内部 
  return 0; //外部 
}
bool isDgnal(const vector<point>poly, int a,int b)
{
	int i,n=poly.size();
	for (i=0;i<n;i++)
		if (i!=a && i!=b && online(poly[a],poly[b],poly[i])) return false;
	for (i=0;i<n;i++)
		if (SegmentProperIntersection(poly[i],poly[(i+1)%n],poly[a],poly[b])) return false;
	point mid=(poly[a]+poly[b])*0.5;
	return (isinpoly(mid,poly)==1);
}
double go(const vector<point> poly)
{
	int i,j,k,n=poly.size();
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			d[i][j]=-1;
	for (i=n-2;i>=0;i--)
		for (j=i+1;j<n;j++)
		{
			double len=Length(poly[i]-poly[j]);
			if (i+1==j) d[i][j]=0;
			else if (!(i==0 && j==n-1) && !isDgnal(poly,i,j)) d[i][j]=INF;
			else
			{
				double m=INF;
				for (k=i+1;k<j;k++)
					m=min(m,d[i][k]+d[k][j]);
				d[i][j]=len+m;
			}
		}
	double len0=Length(poly[0]-poly[n-1]);
	return d[0][n-1]-len0;
}
int main( )
{
	int n,cas=1;
	while (~scanf("%d",&n) && n)
	{
		double x,y;
		vector <point> poly;
		for (int i=0;i<n;i++)
		{
			scanf("%lf%lf",&x,&y);
			poly.push_back(point(x,y));
		}
		printf("Case %d: %.4lf\n",cas++,go(poly));
	}
}
