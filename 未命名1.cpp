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
//����
double multi(Point p0, Point p1, Point p2) {
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
//�ж������߶��Ƿ��ཻ��������ཻ
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
        if (!d5 && !d6) return 1; //�����ཻ
        if (d5 * d6 > 0 || d7 * d8 > 0) return 0; //���ཻ�����¾���벻�ܽ���˳��
        if (!d5 || !d6 || !d7 || !d8) return 2; //����Ϊ�˵�
        return 3; //�淶�ཻ
    }
    return 0;
}
//��б�ʣ���ƽ��y�ᣬ����false�����򣬷���true��k����б��ֵ
bool getSlope(Line l, double &k) {
    double t = l.a.x-l.b.x;
    if (!dblcmp(t)) return false;
    k = (l.a.y - l.b.y) / t;
    return true;
}

void getIntersect(Line l1, Line l2, Point& p) { //���߶ν���
    double A1 = l1.b.y - l1.a.y;
    double B1 = l1.a.x - l1.b.x;
    double C1 = (l1.b.x - l1.a.x) * l1.a.y - (l1.b.y - l1.a.y) * l1.a.x;
    double A2 = l2.b.y - l2.a.y;
    double B2 = l2.a.x - l2.b.x;
    double C2 = (l2.b.x - l2.a.x) * l2.a.y - (l2.b.y - l2.a.y) * l2.a.x;
    p.x = (C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1);
    p.y = (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1);
 }

void getBiggerY(Point a, Point b, Point& p) { //��a,b������y�������ĵ�
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
        !dblcmp(p0.x-p2.x) && !dblcmp(p0.y-p2.y)) //�������4�����5�����Ϊ0�����,��p0��p1��p2Ϊͬһ��ʱ
            return 0;
    Point p;
    if (dblcmp(p1.y-p2.y) >= 0) {
        p.y = p2.y;
        p.x = p0.x + (p1.x - p0.x) * (p2.y - p0.y) / (p1.y - p0.y); //����һ�������
        return fabs(multi(p0, p2, p)) / 2; //��������
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
        if (ok <= 1) ans = 0; //���1�������߶ι����ཻ���߲��ཻ
        else {
            getBiggerY(l1.a, l1.b, p1);
            getBiggerY(l2.a, l2.b, p2);
            getIntersect(l1, l2, p);
            bool f1, f2;
            f1 = getSlope(l1, k1);
            f2 = getSlope(l2, k2);
            if (f1 && f2) { //��������߶�����y��ƽ��
                 if (!dblcmp(k1) || !dblcmp(k2)) ans = 0; //����һ���߶�ƽ��x��ʱ
                 else if (dblcmp(k1*k2) > 0) { //�������߶ε�б�ʷ�����ͬʱ��
                    int d1 = dblcmp(k1-k2);
                    int d2 = dblcmp(k2);
                    //���2��������߶ν�������߶θ���
                    if (d1 > 0 && d2 > 0 && dblcmp(p2.x-p1.x)*dblcmp(p2.x-p.x) <= 0
                       || d1 < 0 && d2 > 0 && dblcmp(p1.x-p2.x)*dblcmp(p1.x-p.x) <= 0
                       || d1 > 0 && d2 < 0 && dblcmp(p1.x-p2.x)*dblcmp(p1.x-p.x) <= 0
                       || d1 < 0 && d2 < 0 && dblcmp(p2.x-p1.x)*dblcmp(p2.x-p.x) <= 0)
                           ans = 0;
                    else  ans = getArea(p, p1, p2); //���3����δ���ǣ������
                 }
                 else ans = getArea(p, p1, p2); //���4���������߶�б�ʷ��Ų�ͬʱ��ֱ�����������ʱ���Ҳ������0��getArea()�����������⴦��
            }
            else ans = getArea(p, p1, p2); //���5������һ���߶�ƽ����y��ʱ��ֱ�����������ʱ���Ҳ������0��getArea()�����������⴦��
        }
        printf ("%.2lf\n", ans);
    }
    return 0;
}

