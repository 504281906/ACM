#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#define eps 1e-8
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
// 获取 两个向量叉积  判断点pot在直线ab的位置，结果为正在左边，结果为负在右边 
double get_Mix( point a,point b,point pot ){
    a.x = a.x - pot.x; a.y = a.y - pot.y;
    b.x = b.x - pot.x; b.y = b.y - pot.y;
    return Cross( a,b );
}
// 直线相交求交点
point get_line_inter( point p,point v, point q,point w ){
    point u = p - q;
    double t = Cross(w,u)/Cross(v,w);
    return p+v*t;
}
// p点到直线 的距离
double dis_p_line( point p,point a,point b ) {
    point v1 = b-a, v2 = p-a;
    return fabs( Cross(v1,v2)/Length(v1) );
}
//点在直线上的投影
inline point GetLineProjection(const point &p,const point &a,const point &b){
    point v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
// 点到线段的距离
double dis_p_segm( point p,point a,point b ){
    if( a == b )return Length( p-a );
    point v1 = b-a,v2 = p-a,v3 = p-b;
    if( dcmp(Dot(v1,v2)) < 0 )return Length(v2);
    else if( dcmp(Dot( v1,v3)) > 0 )return Length(v3);
    else return fabs(Cross( v1,v2 ))/Length(v1);
}
//海伦公式 三条边
double Heron(double a,double b,double c){
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
// 多边形面积 从p[0] 开始，p[n] 结束
double ploy_area( vector<point>p,int n ){
    double area = 0;
    n=p.size();
    for( int i = 1; i < n-1; i++ )
       area += Cross( p[i]-p[0],p[i+1]-p[0] );
    return area/2.0;
}

// 线段相交判断 先必须去掉不相交的状态；再判断方向
bool get_set(const point& a1, const point& a2, const point& b1, const point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<eps && dcmp(c3)*dcmp(c4)<-eps;
}

//判断两条线段是否相交，且如何相交
int get_set1(segment l1, segment l2) {
    int d1, d2, d3, d4, d5, d6, d7, d8;
    d1 = dcmp(max(l1.a.x, l1.b.x) - min(l2.a.x, l2.b.x));
    d2 = dcmp(max(l2.a.x, l2.b.x) - min(l1.a.x, l1.b.x));
    d3 = dcmp(max(l1.a.y, l1.b.y) - min(l2.a.y, l2.b.y));
    d4 = dcmp(max(l2.a.y, l2.b.y) - min(l1.a.y, l1.b.y));
    d5 = dcmp(get_Mix(l1.a, l2.b,l2.a));
    d6 = dcmp(get_Mix(l1.b, l2.b,l2.a));
    d7 = dcmp(get_Mix(l2.a, l1.b,l1.a));
    d8 = dcmp(get_Mix(l2.b, l1.b,l1.a));
    if (d1 >= 0 && d2 >= 0 && d3 >= 0 && d4 >= 0) {
        if (!d5 && !d6) return 1; //共线相交
        if (d5 * d6 > 0 || d7 * d8 > 0) return 0; //不相交，与下句代码不能交换顺序
        if (!d5 || !d6 || !d7 || !d8) return 2; //交点为端点
        return 3; //规范相交
    }
    return 0;
}
// 线段 直线 平行判断只需要对应向量平行；
bool get_pall( point a,point b,point c,point d ){
    if( Cross( a-b,c-d ) == 0 )return true;
    return false;
}

// 直线  重合判断 只需要 一条直线的两点都在直线方向
bool get_doub( point a,point b,point c,point d ){
    if( Cross( d-b,a-b ) == 0 && Cross( c-b,a-b ) == 0 )return 1;
    return 0;
}
// 获取 线段 交点；依据 叉积判断
point get_pot( point a,point b,point c,point d ){
    point temp;
    temp.x = ( c.x*Cross(b-a,d-a) - d.x*Cross(b-a,c-a) )/( Cross(b-a,d-a) - Cross(b-a,c-a) );
    temp.y = ( c.y*Cross(b-a,d-a) - d.y*Cross(b-a,c-a) )/( Cross(b-a,d-a) - Cross(b-a,c-a) );
    return temp;
}
//获取直线的交点  同时也可以是线段的交点；
point get_ppp( point a,point b,point c,point d ){
    double a0 = a.y - b.y; double b0 = b.x - a.x; double c0 = a.x*b.y - b.x*a.y;
    double a1 = c.y - d.y; double b1 = d.x - c.x; double c1 = c.x*d.y - d.x*c.y;
    double D =  a0*b1 - a1*b0; point temp;
    temp.x = ( b0*c1 - b1*c0 )/D;
    temp.y = ( a1*c0 - a0*c1 )/D;
    return temp;
}
//点pot 是否 在线段 ab 上 只需 叉积等于0  点积等于0
bool online( point a,point b,point pot ){
    if( Cross( a - pot,b - pot ) == 0 && Dot( a - pot,b - pot ) <= 0 )return 1;
    return 0;
}
//p为点,poly为多边形 点在多边形内判定
int isPointInPolygon(const point& p, const vector<point> poly){
  int n = poly.size();
  int wn = 0;
  for(int i = 0; i < n; i++){
    const point& p1 = poly[i];
    const point& p2 = poly[(i+1)%n];
    if(p1 == p || p2 == p || online(p1, p2, p)) return -1; 
    int k = dcmp(Cross(p2-p1, p-p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if(k > 0 && d1 <= 0 && d2 > 0) wn++;
    if(k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1; //内部 
  return 0; //外部 
}
int top,res[1123456]; // 凸包 ( 起点 0 ) ( n 个点 ) 自己写的，，需要改进 改进；
void GRA( int n )
{
    sort( node,node+n ); // 先排序
    top = 1; res[0] = 0; res[1] = 1;// 从第0位开始放；前两位不管
    for( int i = 2; i <= n; i++ ){
        while( top  && get_Mix( node[i],node[res[top]],node[res[top-1]] ) > 0 )top--;
        res[++top] = i;
    }
    int k = top;
    for( int i = n-2; i >=  0; i-- ){
        while( top > k && get_Mix( node[i],node[res[top]],node[res[top-1]] ) > 0 )top--;
        res[++top] = i;
    }
    top--; // 会添加进去最后一个点
}
//求两圆相交
int C_T_C( circle c1,circle c2,point &p1,point &p2 ){
    double d = Length( c1.c- c2.c );
    if( dcmp( d ) == 0 ) {
        if( dcmp( c1.r-c2.r ) == 0 ) return -1;//两圆重合
        return 0;
    }
    if( dcmp( c1.r + c2.r - d ) < 0 ) return 0;
    if( dcmp( fabs( c1.r - c2.r ) - d ) > 0 ) return 0;
    double a = Angle( c2.c - c1.c,point( 1,0 ) );
    double da = acos(( c1.r * c1.r + d * d - c2.r * c2.r )/( 2 * c1.r * d ) );
    p1 = c1.PPP( a - da ); p2 = c1.PPP( a + da );
    if( p1 == p2 ) return 1;
    return 2;
}
//圆与直线交点 返回交点个数
int C_T_L( line L,circle C,point &p1,point &p2){
    double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y-C.c.y;
    double e = a*a + c*c, f = 2*(a*b+c*d), g = b*b + d*d -C.r*C.r;
    double delta = f*f - 4*e*g;
    if( dcmp(delta) < 0 )  return 0;//相离
    if( dcmp(delta) == 0 ) {//相切
        p1 = p1 = L.p + L.v*( -f/(2*e) );
        return 1;
    }//相交
    p1 = ( L.p + L.v * ( -f-sqrt(delta) )/( 2*e ) );
    p2 = ( L.p + L.v * ( -f+sqrt(delta) )/( 2*e ) );
    return 2;
}
//点与圆的切线；
int get_P_C_inter( point p,circle c, point *v )
{
    point u = c.c - p; double dist = Length(u);
    if( dist < c.r )return 0;
    else if( dcmp( dist - c.r) == 0 ){
        v[0] = Rotate( u,PI/2 );
        return 1;
    }else {
        double ang = asin( c.r/dist );
        v[0] = Rotate(u,-ang);
        v[1] = Rotate(u,+ang);
        return 2;
    }
    return -1;
}
//判断点d是否在三角形a,b,c内 
bool inthree(const point a,const point b,const point c,const point d)
{
	point A,B,C;
	A=a-d;
	B=b-d;
	C=c-d;
	double s,s1;
	s=Cross(A,B)/2+Cross(A,C)/2+Cross(B,C)/2;
	s1=Cross(c-b,a-b)/2;
	if (fabs(s-s1)<eps) return true;
	else return false;
}
// 外接圆圆心。假定三点不共线
point get_circumscribed_center(point p1, point p2, point p3) {
  double bx = p2.x - p1.x;
  double by = p2.y - p1.y;
  double cx = p3.x - p1.x;
  double cy = p3.y - p1.y;
  double d = 2 * (bx * cy - by * cx);
  point p;
  p.x = (cy * (bx * bx + by * by) - by * (cx * cx + cy * cy)) / d + p1.x;
  p.y = (bx * (cx * cx + cy * cy) - cx * (bx * bx + by * by)) / d + p1.y;
  return p;
}
double CS(circle a,circle b){    //求两圆相交面积 
	double d=sqrt((a.c.x-b.c.x)*(a.c.x-b.c.x)+(a.c.y-b.c.y)*(a.c.y-b.c.y));
	if (a.r<b.r){
		circle g;
		g=a;
		a=b;
		b=g;
	}
	if (a.r+b.r<=d) return 0; //两圆相离 
	if (a.r-b.r>=d){
		return (pi*b.r*b.r);
	}  //大圆包含小圆 
	double a1=acos((d*d+a.r*a.r-b.r*b.r)/(2*a.r*d));
	double b1=acos((d*d+b.r*b.r-a.r*a.r)/(2*b.r*d));
	double s=a1*a.r*a.r+b1*b.r*b.r;
	double s1=a.r*d*sin(a1);
	return s-s1;
}
void getbigy(point a,point b,point &p){
	if (dcmp(a.y-b.y)>0) p=a;
	else p=b;
}
bool getk(segment l,double &k){
	double t=l.a.x-l.b.x;
	if (!dcmp(t)) return false;
	k=(l.a.y-l.b.y)/t;
	return true;
}
double k1,k2;
double getans(point p,point p1,point p2){
	if (p==p1 || p==p2) return 0;
	point g;
	if (dcmp(p1.y-p2.y)>=0){
		g.y=p2.y;
		g.x=p.x+(p1.x-p.x)/(p1.y-p.y)*(p2.y-p.y);
		return fabs(get_Mix(g,p2,p))/2;
	}else{
		g.y=p1.y;
		g.x=p.x+(p2.x-p.x)/(p2.y-p.y)*(p1.y-p.y);
		return fabs(get_Mix(g,p1,p))/2;
	}
}
int main(){
	int T;
	double ans;
	point p0,p1,p2;
	scanf("%d",&T);
	segment l1,l2;
	while (T--){
		scanf ("%lf%lf%lf%lf%lf%lf%lf%lf", &l1.a.x, &l1.a.y, &l1.b.x, &l1.b.y, &l2.a.x, &l2.a.y, &l2.b.x, &l2.b.y);
		if (get_set1(l1,l2)<=1) ans=0;
		else{
			getbigy(l1.a,l1.b,p1);
			getbigy(l2.a,l2.b,p2);
			p0=get_pot(l1.a,l1.b,l2.a,l2.b);
			if (getk(l1,k1)&&getk(l2,k2)){
				if (!dcmp(k1) || !dcmp(k2)) ans=0;
				else if (dcmp(k1*k2)>0){
					int d1,d2;
					d1=dcmp(k1-k2);
					d2=dcmp(k2);
					if (d1>0 && d2>0 && dcmp(p2.x-p0.x)*dcmp(p2.x-p1.x)<=0
					|| d1<0 && d2>0 && dcmp(p1.x-p0.x)*dcmp(p1.x-p2.x)<=0
					|| d1>0 && d2<0 && dcmp(p1.x-p0.x)*dcmp(p1.x-p2.x)<=0
					|| d1<0 && d2<0 && dcmp(p2.x-p0.x)*dcmp(p2.x-p1.x)<=0)
						ans=0;
					else ans=getans(p0,p1,p2);
				}else ans=getans(p0,p1,p2);
			}else ans=getans(p0,p1,p2);
		}
		printf("%.2f\n",ans+eps);
	}
	return 0;
}
