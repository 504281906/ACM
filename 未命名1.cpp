#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-8;

struct Point {
    double x, y;
};

struct Line {
    Point a, b;
} l1, l2;

double Max(double a, double b) {
   return a > b ? a : b;
}

double Min(double a, double b) {
   return a > b ? b : a;
}

int dblcmp(double d) {
   if (fabs(d) < eps) return 0;
   return d > 0 ? 1 : -1;
}
//求叉积
double multi(Point p0, Point p1, Point p2) {
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
//判断两条线段是否相交，且如何相交
int cross(Line l1, Line l2) {
    int d1, d2, d3, d4, d5, d6, d7, d8;
    d1 = dblcmp(Max(l1.a.x, l1.b.x) - Min(l2.a.x, l2.b.x));
    d2 = dblcmp(Max(l2.a.x, l2.b.x) - Min(l1.a.x, l1.b.x));
    d3 = dblcmp(Max(l1.a.y, l1.b.y) - Min(l2.a.y, l2.b.y));
    d4 = dblcmp(Max(l2.a.y, l2.b.y) - Min(l1.a.y, l1.b.y));
    d5 = dblcmp(multi(l2.a, l1.a, l2.b));
    d6 = dblcmp(multi(l2.a, l1.b, l2.b));
    d7 = dblcmp(multi(l1.a, l2.a, l1.b));
    d8 = dblcmp(multi(l1.a, l2.b, l1.b));
    if (d1 >= 0 && d2 >= 0 && d3 >= 0 && d4 >= 0) {
        if (!d5 && !d6) return 1; //共线相交
        if (d5 * d6 > 0 || d7 * d8 > 0) return 0; //不相交，与下句代码不能交换顺序
        if (!d5 || !d6 || !d7 || !d8) return 2; //交点为端点
        return 3; //规范相交
    }
    return 0;
}
//求斜率，若平行y轴，返回false；否则，返回true，k返回斜率值
bool getSlope(Line l, double &k) {
    double t = l.a.x-l.b.x;
    if (!dblcmp(t)) return false;
    k = (l.a.y - l.b.y) / t;
    return true;
}

void getIntersect(Line l1, Line l2, Point& p) { //求线段交点
    double A1 = l1.b.y - l1.a.y;
    double B1 = l1.a.x - l1.b.x;
    double C1 = (l1.b.x - l1.a.x) * l1.a.y - (l1.b.y - l1.a.y) * l1.a.x;
    double A2 = l2.b.y - l2.a.y;
    double B2 = l2.a.x - l2.b.x;
    double C2 = (l2.b.x - l2.a.x) * l2.a.y - (l2.b.y - l2.a.y) * l2.a.x;
    p.x = (C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1);
    p.y = (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1);
 }

void getBiggerY(Point a, Point b, Point& p) { //求a,b两点中y坐标更大的点
    if (dblcmp(a.y-b.y) > 0) {
        p.x = a.x;
        p.y = a.y;
    } else {
        p.x = b.x;
        p.y = b.y;
    }
}

double getArea(Point p0, Point p1, Point p2) {
    if (!dblcmp(p0.x-p1.x) && !dblcmp(p0.y-p1.y) ||
        !dblcmp(p0.x-p2.x) && !dblcmp(p0.y-p2.y)) //处理情况4，情况5的面积为0的情况,即p0与p1或p2为同一点时
            return 0;
    Point p;
    if (dblcmp(p1.y-p2.y) >= 0) {
        p.y = p2.y;
        p.x = p0.x + (p1.x - p0.x) * (p2.y - p0.y) / (p1.y - p0.y); //求另一点的坐标
        return fabs(multi(p0, p2, p)) / 2; //叉积求面积
    }
    else {
        p.y = p1.y;
        p.x = p0.x + (p2.x - p0.x) * (p1.y - p0.y) / (p2.y - p0.y);
        return fabs(multi(p0, p1, p)) / 2;
    }
}

int main()
{
    int t;
    double k1, k2, ans;
    Point p, p1, p2;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%lf%lf%lf%lf%lf%lf%lf%lf", &l1.a.x, &l1.a.y, &l1.b.x, &l1.b.y, &l2.a.x, &l2.a.y, &l2.b.x, &l2.b.y);
        int ok = cross(l1, l2);
        if (ok <= 1) ans = 0; //情况1：两条线段共线相交或者不相交
        else {
            getBiggerY(l1.a, l1.b, p1);
            getBiggerY(l2.a, l2.b, p2);
            getIntersect(l1, l2, p);
            bool f1, f2;
            f1 = getSlope(l1, k1);
            f2 = getSlope(l2, k2);
            if (f1 && f2) { //如果两条线都不与y轴平行
                 if (!dblcmp(k1) || !dblcmp(k2)) ans = 0; //当有一条线段平行x轴时
                 else if (dblcmp(k1*k2) > 0) { //当两条线段的斜率符号相同时，
                    int d1 = dblcmp(k1-k2);
                    int d2 = dblcmp(k2);
                    //情况2：上面的线段将下面的线段覆盖
                    if (d1 > 0 && d2 > 0 && dblcmp(p2.x-p1.x)*dblcmp(p2.x-p.x) <= 0
                       || d1 < 0 && d2 > 0 && dblcmp(p1.x-p2.x)*dblcmp(p1.x-p.x) <= 0
                       || d1 > 0 && d2 < 0 && dblcmp(p1.x-p2.x)*dblcmp(p1.x-p.x) <= 0
                       || d1 < 0 && d2 < 0 && dblcmp(p2.x-p1.x)*dblcmp(p2.x-p.x) <= 0)
                           ans = 0;
                    else  ans = getArea(p, p1, p2); //情况3：若未覆盖，求面积
                 }
                 else ans = getArea(p, p1, p2); //情况4：当两条线段斜率符号不同时，直接求面积，此时面积也可能是0，getArea()函数中有特殊处理
            }
            else ans = getArea(p, p1, p2); //情况5：当有一条线段平行于y轴时，直接求面积，此时面积也可能是0，getArea()函数中有特殊处理
        }
        printf ("%.2lf\n", ans);
    }
    return 0;
}

