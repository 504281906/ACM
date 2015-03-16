#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#define eps 1e-9
#include<vector>
using namespace std;
const double PI = acos(-1.0);
int dcmp( double x ){ if( fabs(x) < eps ) return 0;else return x < 0?-1:1; }
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

double Dot( point a,point b ){return a.x*b.x + a.y*b.y;} // �㵽��ľ���  //��� ab=|a||b|cos@
double Length( point a ){return sqrt( Dot( a,a ) );}    // ��������
double Angle( point a,point b ){ return acos( Dot(a,b)/Length(a)/Length(b) );} // ���������ĽǶ�
double D_T_D(const double &deg ){ return deg/180.0*PI; }

// ������ת rad ���� rad>0��ʱ�룬rad<0˳ʱ��
point Rotate( point a, double rad ){
     return point( a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad) );
}
// ������ �������� �ĵ�λ���� ==������ʱ����ת90��
point Normal( point a ){
     double L = Length(a); 
	 return point(-a.y/L,a.x/L);
}
// �������   a*b=|a||b|sin@;
double Cross( point a,point b ){
    return a.x*b.y - a.y*b.x;
}
// ��ȡ �����������  
double get_Mix( point a,point b,point pot ){
    a.x = a.x - pot.x; a.y = a.y - pot.y;
    b.x = b.x - pot.x; b.y = b.y - pot.y;
    return Cross( a,b );
}
// ֱ���ཻ�󽻵�
point get_line_inter( point p,point v, point q,point w ){
    point u = p - q;
    double t = Cross(w,u)/Cross(v,w);
    return p+v*t;
}
// p�㵽ֱ�� �ľ���
double dis_p_line( point p,point a,point b ) {
    point v1 = b-a, v2 = p-a;
    return fabs( Cross(v1,v2)/Length(v1) );
}
//����ֱ���ϵ�ͶӰ
inline point GetLineProjection(const point &p,const point &a,const point &b){
    point v=b-a;
    return a+v*(Dot(v,p-a)/Dot(v,v));
}
// �㵽�߶εľ���
double dis_p_segm( point p,point a,point b ){
    if( a == b )return Length( p-a );
    point v1 = b-a,v2 = p-a,v3 = p-b;
    if( dcmp(Dot(v1,v2)) < 0 )return Length(v2);
    else if( dcmp(Dot( v1,v3)) > 0 )return Length(v3);
    else return fabs(Cross( v1,v2 ))/Length(v1);
}
//���׹�ʽ ������
double Heron(double a,double b,double c){
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
// �������� ��p[0] ��ʼ��p[n] ����
double ploy_area( vector<point>p,int n ){
    double area = 0;
    n=p.size();
    for( int i = 1; i < n-1; i++ )
       area += Cross( p[i]-p[0],p[i+1]-p[0] );
    return area/2.0;
}
// �߶��ཻ�ж� �ȱ���ȥ�����ཻ��״̬�����жϷ���
bool get_set(const point& a1, const point& a2, const point& b1, const point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
// �߶� ֱ�� ƽ���ж�ֻ��Ҫ��Ӧ����ƽ�У�
bool get_pall( point a,point b,point c,point d ){
    if( Cross( a-b,c-d ) == 0 )return true;
    return false;
}
// ֱ��  �غ��ж� ֻ��Ҫ һ��ֱ�ߵ����㶼��ֱ�߷���
bool get_doub( point a,point b,point c,point d ){
    if( Cross( d-b,a-b ) == 0 && Cross( c-b,a-b ) == 0 )return 1;
    return 0;
}
// ��ȡ �߶� ���㣻���� ����ж�
point get_pot( point a,point b,point c,point d ){
    point temp;
    temp.x = ( c.x*Cross(b-a,d-a) - d.x*Cross(b-a,c-a) )/( Cross(b-a,d-a) - Cross(b-a,c-a) );
    temp.y = ( c.y*Cross(b-a,d-a) - d.y*Cross(b-a,c-a) )/( Cross(b-a,d-a) - Cross(b-a,c-a) );
    return temp;
}
//��ȡֱ�ߵĽ���  ͬʱҲ�������߶εĽ��㣻
point get_ppp( point a,point b,point c,point d ){
    double a0 = a.y - b.y; double b0 = b.x - a.x; double c0 = a.x*b.y - b.x*a.y;
    double a1 = c.y - d.y; double b1 = d.x - c.x; double c1 = c.x*d.y - d.x*c.y;
    double D =  a0*b1 - a1*b0; point temp;
    temp.x = ( b0*c1 - b1*c0 )/D;
    temp.y = ( a1*c0 - a0*c1 )/D;
    return temp;
}
//��pot �Ƿ� ���߶� ab �� ֻ�� �������0  �������0
bool online( point a,point b,point pot ){
    if( Cross( a - pot,b - pot ) == 0 && Dot( a - pot,b - pot ) <= 0 )return 1;
    return 0;
}
//pΪ��,polyΪ����� ���ڶ�������ж�
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
  if (wn != 0) return 1; //�ڲ� 
  return 0; //�ⲿ 
}
int top,res[1123456]; // ͹�� ( ��� 0 ) ( n ���� ) �Լ�д�ģ�����Ҫ�Ľ� �Ľ���
void GRA( int n )
{
    sort( node,node+n ); // ������
    top = 1; res[0] = 0; res[1] = 1;// �ӵ�0λ��ʼ�ţ�ǰ��λ����
    for( int i = 2; i <= n; i++ ){
        while( top  && get_Mix( node[i],node[res[top]],node[res[top-1]] ) > 0 )top--;
        res[++top] = i;
    }
    int k = top;
    for( int i = n-2; i >=  0; i-- ){
        while( top > k && get_Mix( node[i],node[res[top]],node[res[top-1]] ) > 0 )top--;
        res[++top] = i;
    }
    top--; // ����ӽ�ȥ���һ����
}
//����Բ�ཻ
int C_T_C( circle c1,circle c2,point &p1,point &p2 ){
    double d = Length( c1.c- c2.c );
    if( dcmp( d ) == 0 ) {
        if( dcmp( c1.r-c2.r ) == 0 ) return -1;//��Բ�غ�
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
//Բ��ֱ�߽��� ���ؽ������
int C_T_L( line L,circle C,point &p1,point &p2){
    double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y-C.c.y;
    double e = a*a + c*c, f = 2*(a*b+c*d), g = b*b + d*d -C.r*C.r;
    double delta = f*f - 4*e*g;
    if( dcmp(delta) < 0 )  return 0;//����
    if( dcmp(delta) == 0 ) {//����
        p1 = p1 = L.p + L.v*( -f/(2*e) );
        return 1;
    }//�ཻ
    p1 = ( L.p + L.v * ( -f-sqrt(delta) )/( 2*e ) );
    p2 = ( L.p + L.v * ( -f+sqrt(delta) )/( 2*e ) );
    return 2;
}
//����Բ�����ߣ�
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
//�жϵ�d�Ƿ���������a,b,c�� 
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
int main( )
{
}
