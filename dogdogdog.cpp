#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const double eps = 1e-10;
#define MAXD 50 + 10
#define _PI acos(-1.0)
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) { }
	bool operator < (const Point& a) const
	{
		if(a.x != x) return x < a.x;
		return y < a.y;
	}
};

typedef Point Vector;
Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (Point A, Point B)   { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }
int dcmp(double x)
{
	if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
bool operator == (const Point& a, const Point &b)
{
	return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}
double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Dist(Point A,Point B){return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));}
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
double Area2(Point A, Point B, Point C) { return Cross(B-A, C-A); }
Vector Rotate(Vector A, double rad)
{
	return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));
}
double DistToSegment(Point P,Point A,Point B){
    if(A == B) return Length(P - A);
    Vector v1 = B - A , v2 = P - A , v3 = P - B;
    if(dcmp(Dot(v1,v2)) < 0) return Length(v2);
    if(dcmp(Dot(v1,v3)) > 0) return Length(v3);
    return fabs(Cross(v1,v2) / Length(v1));
}
Point GetIntersection(Point P, Vector v, Point Q, Vector w)
{
	Vector u = P-Q;
	double t = Cross(w, u) / Cross(v, w);
	return P+v*t;
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1);
	double c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
double PolygonArea(Point* p, int n)
{
	double area = 0;
	for(int i = 1; i < n-1; i++)
		area += Cross(p[i]-p[0], p[i+1]-p[0]);
	return area;
}
bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}
Point Pa[MAXD],Pb[MAXD];
int na,nb;
double La,Lb;
double Min ,Max;
void init(){
    scanf("%d%d",&na,&nb);
    La = 0; Lb = 0;
    Min = 1e20;
    Max = 0;
    for(int i = 0 ; i < na ; i++){
        scanf("%lf%lf",&Pa[i].x,&Pa[i].y);
        if(i > 0){
            La += Length(Pa[i] - Pa[i - 1]);
            //La += Dist(Pa[i] , Pa[i - 1]);
        }
    }
    for(int i = 0 ; i < nb ; i++){
        scanf("%lf%lf",&Pb[i].x,&Pb[i].y);
        if(i > 0){
            Lb += Length(Pb[i] - Pb[i - 1]);
            //Lb += Dist(Pb[i] , Pb[i - 1]);
        }
    }
}
void update(Point p,Point a,Point b){
    Min = min(Min,DistToSegment(p,a,b));
    Max = max(Max, Length(p - a));
    Max = max(Max, Length(p - b));
}
double solve(){         //假设a、b狗的速度分别为La、Lb
    Point pos_a = Pa[0];//a狗当前位置
    Point pos_b = Pb[0];//b狗当前位置
    for(int next_a = 0,next_b = 0 ; next_a < na - 1 && next_b < nb - 1; ){
        double Ta = Dist(Pa[next_a + 1],pos_a);          //a到下一个拐点的距离
        double Tb = Dist(Pb[next_b + 1],pos_b);          //b到下一个拐点的距离
        double  T = min(Ta / La,Tb / Lb);                //最短时间
        Vector Va = (Pa[next_a + 1] - pos_a) / Ta * T * La;
        Vector Vb = (Pb[next_b + 1] - pos_b) / Tb * T * Lb;
        update(pos_a,pos_b,pos_b + Vb - Va);
        pos_a = pos_a + Va;
        pos_b = pos_b + Vb;
        if(pos_a == Pa[next_a + 1]) next_a ++;
        if(pos_b == Pb[next_b + 1]) next_b ++;
    }
    //printf("%lf %lf\n",Max,Min);
    return (Max - Min);
}
int main(){
    int T,Case = 1;
    scanf("%d",&T);
    while(T--){
        init();
        printf("Case %d: %.0lf\n",Case++,solve());
    }
    return 0;
}
