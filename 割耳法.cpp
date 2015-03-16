#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
 
const double eps = 1e-10;
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
 
struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};
 
typedef Point Vector;
 
Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
 
bool operator < (const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}
 
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
 
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
 
bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}
 
typedef vector<Point> Polygon;
 
int isPointInPolygon(const Point& p, const Polygon& poly){
  int n = poly.size();
  int wn = 0;
  for(int i = 0; i < n; i++){
    const Point& p1 = poly[i];
    const Point& p2 = poly[(i+1)%n];
    if(p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1; // ????????????
    int k = dcmp(Cross(p2-p1, p-p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if(k > 0 && d1 <= 0 && d2 > 0) wn++;
    if(k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1; // ??????
  return 0; // ??????
}
 
const int maxn = 100 + 5;
 
bool isDiagonal(const Polygon& poly, int a, int b) {
  int n = poly.size();
  for(int i = 0; i < n; i++)
    if(i != a && i != b && OnSegment(poly[i], poly[a], poly[b])) return false; // ????????????????????????
  for(int i = 0; i < n; i++)
    if(SegmentProperIntersection(poly[i], poly[(i+1)%n], poly[a], poly[b])) return false; // ????????????????????????????????????
  Point midp = (poly[a] + poly[b]) * 0.5;
  return (isPointInPolygon(midp, poly) == 1); // ???????????????????????????
}

const double INF = 1e9;
double d[maxn][maxn];
 
double solve(const Polygon& poly) {
  int n = poly.size();
 
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) d[i][j] = -1;
  for(int i = n-2; i >= 0; i--)
    for(int j = i+1; j < n; j++) {
      double len = Length(poly[i] - poly[j]);
      if(i + 1 == j) d[i][j] = 0;
      else if(!(i == 0 && j == n-1) && !isDiagonal(poly, i, j)) d[i][j] = INF;
      else {
        double m = INF;
        for(int k = i+1; k < j; k++) {
          if(d[i][k] < 0 || d[k][j] < 0) printf("!!!\n");
          m = min(m, d[i][k] + d[k][j]);
        }
        d[i][j] = len + m;
      }
    }
  double len0 = Length(poly[0] - poly[n-1]);
  return d[0][n-1] - len0;
}
int main() {
  int n, kase = 0;
  while(scanf("%d", &n) == 1 && n > 0) {
    double x, y;
    Polygon poly;
    for(int i = 0; i < n; i++) { scanf("%lf%lf", &x, &y); poly.push_back(Point(x,y)); }
    printf("Case %d: %.4lf\n", ++kase, solve(poly));
  }
  return 0;
}
