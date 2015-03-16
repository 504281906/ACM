#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <ext/hash_map>
#include <ext/hash_set>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
namespace Orz {
    #define clr(a,b) memset(a, b, sizeof(a))
    #define cpy(a,b) memcpy(a, b, sizeof(a))
    #define rep(i,a,b) for(int i=a; i<b; i++)
    #define per(i,a,b) for(int i=b-1; i>=a; i--)
    #define foreach(i,a) for(__typeof((a).begin()) i=a.begin(); i!=(a).end(); ++i)
    #define iter(c) __typeof((c).begin())
    #define TTI template <class T> inline
    #define pb(a) push_back(a)
    #define mp(a,b) make_pair(a,b)

    using namespace std;
    using namespace __gnu_cxx;

    typedef long long ll;
    typedef unsigned long long uu;
    typedef pair<int,int> pii;

    const int INF = 0x3f3f3f3f;
    int MOD = 1e9+7;

    const double eps = 1e-8;
    const double inf = 1e20;
    const double pi = acos(-1.0);

    char cread;
    bool cfushu;
    inline void read(int &x) {
        while((cread=getchar())<'0'); x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
    }
    inline void read(ll &x) {
        while((cread=getchar())<'0'); x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
    }
    inline void read(char *x) {
        while((cread=getchar())<'a'); (*x++) = cread;
        while((cread=getchar())>='a') (*x++) = cread;
        *x = 0;
    }
    inline void getInt(int & x) {
        while((cread=getchar())<'-');
        if(cread == '-') cfushu = true, x = 0;
        else cfushu = false, x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
        if(cfushu) x = -x;
    }
    inline void getInt(ll & x) {
        while((cread=getchar())<'-');
        if(cread == '-') cfushu = true, x = 0;
        else cfushu = false, x = cread - '0';
        while((cread=getchar())>='0') x = x * 10 + cread - '0';
        if(cfushu) x = -x;
    }

    inline int add(int a, int b) { a += b; if(a >= MOD) a -= MOD; return a; }
    inline int mul(int a, int b) { return ll(a) * ll(b) % MOD; }
    inline int powmod(int x, int y) {
        int ret = 1;
        while(y) {
            if(y & 1) ret = mul(ret, x);
            x = mul(x, x);
            y >>= 1;
        }
        return ret;
    }
    inline int __extgcd(int a, int b, int &x, int &y) { //gcd(a,b) == a*x + b*y
        if(b == 0) {
            x = 1; y = 0; return a;
        } else {
            int ret = __extgcd(b, a%b, x, y);
            int temp = x;
            x = y;
            y = temp - a/b*y;
            return ret;
        }
    }

    TTI void checkmax(T & a, T b) { if(b>a) a=b; }
    TTI void checkmin(T & a, T b) { if(b<a) a=b; }
    TTI void sqr(T x) { return x*x; }
    inline int sgn(double x) { if(x < -eps) return -1; if(x > eps) return 1; return 0; }

    const int cx[] = {-1, 0, 1, 0};
    const int cy[] = {0, 1, 0, -1};
}
using namespace Orz;
const int N = 100100;

inline bool eq(double x, double y) { return (x-y<-eps)?0:x-y<eps; }

struct Point {
    double x, y;
    int c;
    Point(){};
    Point(double x, double y):x(x),y(y){};

    static double xmult(const Point &ps, const Point &pe, const Point &po) {
        return (ps.x-po.x)*(pe.y-po.y)-(pe.x-po.x) *(ps.y-po.y);
    }
    double operator *(const Point &b) const {
        return x*b.y-y*b.x;
    }
    double operator ^(const Point &b) const {
        return x*b.x+y*b.y;
    }
    Point operator-(const Point &b) const {
        return Point(x-b.x, y-b.y);
    }
    bool operator ==(const Point &b) const {
        return fabs(b.x-x) < eps && fabs(b.y-y) < eps;
    }
    bool operator !=(const Point &b) const {
        return((*this) == b) == false;
    }
    double dis2(const Point &b) const {
        return(x-b.x) *(x-b.x) +(y-b.y) *(y-b.y);
    }
    double dis(const Point &b) const {
        return sqrt((x-b.x) *(x-b.x) +(y-b.y) *(y-b.y));
    }
    Point operator / (const double & b) const {
        return Point(x / b, y / b);
    }
    Point operator + (const Point & b) const {
        return Point(x + b.x, y + b.y);
    }
};

struct Vec2
{
    Point s, e;
    double a, b, c;
    Vec2(){}
    Vec2(const Point &s, const Point &e):s(s),e(e){}
    //�������Ĳ��,��������[vb]
    //[���������λ���ж�]
    double operator *(const Point &vb) const {
        return (vb.y-s.y)*(e.x-s.x)-(vb.x-s.x)*(e.y-s.y);
    }
    //�����������Ĳ��,����������[vb]
    double operator *(const Vec2 &vb) const {
        return (e.x-s.x)*(vb.e.y-vb.s.y)-(e.y-s.y)*(vb.e.x-vb.s.x);
    }
    //�������ʾת��Ϊһ���ʾ
    bool pton() {
        a = s.y-e.y;
        b = e.x-s.x;
        c = s.x*e.y-s.y*e.x;
        return true;
    }
    //-----------���ֱ�ߣ�������-----------
    //����������ߣ��ұߵ�С�ںŸĳɴ��ںż���,�ڶ�Ӧֱ���������=�ţ�
    //��������[vb],����[vc]
    friend bool operator<(const Point &vb, const Vec2 &vc) {
        return (vc.e.y-vc.s.y)*(vb.x-vc.s.x) < (vb.y-vc.s.y)*(vc.e.x-vc.s.x);
    }
    //����ֱ����,��������[vb]
    bool lhas(const Point &vb) const {
        return fabs((*this)*vb) < eps;
    }
    //�����߶���,��������[vb]
    bool shas(const Point &vb) const {
        return lhas(vb)
            && vb.x-min(s.x, e.x) > -eps && vb.x-max(s.x, e.x) < eps
            && vb.y-min(s.y, e.y) > -eps && vb.y-max(s.y, e.y) < eps;
    }
    //�㵽ֱ��/�߶εľ���
    //������ ��[vb], �Ƿ����߶�[isSegment](Ĭ��Ϊֱ��)
    double dis(const Point &vb, bool isSegment = false) {
        pton();
        double td = (a*vb.x + b*vb.y + c) / sqrt(a*a + b*b);
        if(isSegment)
        {
            double xp = (b*b*vb.x-a*b*vb.y-a*c) / ( a*a + b*b);
            double yp = (-a*b*vb.x + a*a*vb.y-b*c) / (a*a + b*b);
            double xb = max(s.x, e.x);
            double yb = max(s.y, e.y);
            double xs = s.x + e.x-xb;
            double ys = s.y + e.y-yb;
            if(xp > xb + eps || xp < xs-eps || yp > yb + eps || yp < ys-eps)
                td = min(vb.dis(s), vb.dis(e));
        }
        return fabs(td);
    }
    //����ֱ�߶ԳƵĵ�
    Point mirror(const Point &vb) const {
        //ע����תΪһ��ʽ
        Point ret;
        double d = a*a + b*b;
        ret.x = (b*b*vb.x-a*a*vb.x-2*a*b*vb.y-2*a*c) / d;
        ret.y = (a*a*vb.y-b*b*vb.y-2*a*b*vb.x-2*b*c) / d;
        return ret;
    }
    //����������д���
    static Vec2 ppline(const Point &_a, const Point &_b) {
        Vec2 ret;
        ret.s.x = (_a.x + _b.x) / 2;
        ret.s.y = (_a.y + _b.y) / 2;
        //һ��ʽ
        ret.a = _b.x-_a.x;
        ret.b = _b.y-_a.y;
        ret.c = (_a.y-_b.y)*ret.s.y + (_a.x-_b.x)*ret.s.x;
        //����ʽ
        if(fabs(ret.a) > eps)
        {
            ret.e.y = 0.0;
            ret.e.x =-ret.c / ret.a;
            if(ret.e == ret. s)
            {
                ret.e.y = 1e10;
                ret.e.x =-(ret.c-ret.b*ret.e.y) / ret.a;
            }
        }
        else
        {
            ret.e.x = 0.0;
            ret.e.y =-ret.c / ret.b;
            if(ret.e == ret. s)
            {
                ret.e.x = 1e10;
                ret.e.y =-(ret.c-ret.a*ret.e.x) / ret.b;
            }
        }
        return ret;
    }
    //------------ֱ�ߺ�ֱ�ߣ�������-------------
    //ֱ���غ�,������ֱ������[vb]
    bool equal(const Vec2 &vb) const {
        return lhas(vb.e) && lhas(vb.s);
    }
    //ֱ��ƽ�У�������ֱ������[vb]
    bool parallel(const Vec2 &vb) const {
        return fabs((*this)*vb) < eps;
    }
    //��ֱ�߽��㣬������Ŀ��ֱ��[vb]
    Point crossLPt(Vec2 vb) {
        //ע�����ж�ƽ�к��غ�
        Point ret = s;
        double t = ((s.x-vb.s.x)*(vb.s.y-vb.e.y)-(s.y-vb.s.y)*(vb.s.x-vb.e.x))
                / ((s.x-e.x)*(vb.s.y-vb.e.y)-(s.y-e.y)*(vb.s.x-vb.e.x));
        ret.x += (e.x-s.x)*t;
        ret.y += (e.y-s.y)*t;
        return ret;
    }
    //------------�߶κ�ֱ�ߣ�������----------
    //�߶κ�ֱ�߽�
    //�������߶�[vb]
    bool crossSL(const Vec2 &vb) const {
        double rs = (*this)*vb.s;
        double re = (*this)*vb.e;
        return rs*re < eps;
    }
    //------------�߶κ��߶Σ�������----------
    //�ж��߶��Ƿ��ཻ(ע�����eps)���������߶�[vb]
    bool isCrossSS(const Vec2 &vb) const {
        //1.�����ų������ж��������߶�Ϊ�Խ��ߵ����������Ƿ��ཻ
        //2.�������飨����0ʱ�˵��غϣ�
        return (
            (max(s.x, e.x) >= min(vb.s.x, vb.e.x)) &&
            (max(vb.s.x, vb.e.x) >= min(s.x, e.x)) &&
            (max(s.y, e.y) >= min(vb.s.y, vb.e.y)) &&
            (max(vb.s.y, vb.e.y) >= min(s.y, e.y)) &&
            ((Vec2(vb.s, s)*vb)*(vb*Vec2(vb.s, e))>=0.0) &&
            ((Vec2(s, vb.s)*(*this))*((*this)*Vec2(s,vb.e))>=0.0)
            );
    }
    //�����뵱ǰֱ�ߴ�ֱ��һ������
    Point getVertical() {
        return Point(s.y-e.y, e.x-s.x);
    }
};

struct Circle {
    Point c;//Բ��
    double r;//�뾶
    double db, de;//Բ��������㣬 Բ�������յ�(��ʱ��0-360)
    //-------Բ��-------
    //Բ������Բ�صõ�Բ����������Բ[cb]
    Circle operator-(Circle &cb) const {
        //ע��Բ�����ཻ��Բ�Ĳ����غ�
        double d2 = c.dis2(cb.c);
        double d = c.dis(cb.c);
        double ans = acos((d2 + r * r - cb.r * cb.r) / (2 * d * r));
        Point py = cb.c - c;
        double oans = atan2(py.y, py.x);
        Circle res;
        res.c = c;
        res.r = r;
        res.db = oans + ans;
        if(res.db < 0) res.db += 2*pi;
        if(res.db == 2*pi) res.db = 0;
        res.de = oans - ans + 2 * pi;
        if(res.de < 0) res.de += 2*pi;
        if(res.de == 2*pi) res.de = 0;

        return res;
    }
    //Բ������Բ�صõ�Բ����������Բ[cb]
    Circle operator+(Circle &cb) const {
        //ע��Բ�����ཻ��Բ�Ĳ����غ�
        double d2 = c.dis2(cb.c);
        double d = c.dis(cb.c);
        double ans = acos((d2 + r * r - cb.r * cb.r) / (2 * d * r));
        Point py = cb.c - c;
        double oans = atan2(py.y, py.x);
        Circle res;
        res.c = c;
        res.r = r;
        res.db = oans - ans;
        if(res.db < 0) res.db += 2*pi;
        if(res.db == 2*pi) res.db = 0;
        res.de = oans + ans;
        if(res.de < 0) res.de += 2*pi;
        if(res.de == 2*pi) res.de = 0;
        return res;
    }
    //��Բ��һ�����������
    //��������[cb](������Բ��),���أ���������(���ߵ�s��Ϊcb,e��Ϊ�е�)
    pair<Vec2, Vec2>  tangent(const Point &cb) const {
        double d = c.dis(cb);
        //����Ƕ�ƫ�Ƶķ�ʽ
        double angp = acos(r / d), ango = atan2(cb.y - c.y, cb.x - c.x);
        Point pl = Point(c.x + r * cos(ango + angp), c.y + r * sin(ango + angp)),
               pr = Point(c.x + r * cos(ango - angp), c.y + r * sin(ango - angp));
        return make_pair(Vec2(cb, pl), Vec2(cb, pr));
    }
    //����ֱ�ߺ�Բ����������
    //������ֱ��[cb](����ʽ)�������������㣬ע��ֱ�߱����Բ����������
    pair<Point, Point> cross(Vec2 cb) const {
        cb.pton();
        //��ֱ�ߴ���ľ���
        double td = fabs(cb.a * c.x + cb.b * c.y + cb.c) / sqrt(cb.a * cb.a + cb.b * cb.b);
        //���㴹������
        double xp = (cb.b * cb.b * c.x - cb.a * cb.b * c.y - cb.a * cb.c) / ( cb.a * cb.a + cb.b * cb.b);
        double yp = (- cb.a * cb.b * c.x + cb.a * cb.a * c.y - cb.b * cb.c) / (cb.a * cb.a + cb.b * cb.b);

        double ango = atan2(yp - c.y, xp - c.x);
        double angp = acos(td / r);

        return make_pair(Point(c.x + r * cos(ango + angp), c.y + r * sin(ango + angp)),
               Point(c.x + r * cos(ango - angp), c.y + r * sin(ango - angp)));
    }

    //����Բ������
    int getTangents(Circle B, Point * a, Point * b) {
        Circle A = *this;
        int cnt = 0;
        if(A.r < B.r) { swap(A, B); swap(a, b); }
        double d2 = (A.c.x-B.c.x)*(A.c.x-B.c.x)+(A.c.y-B.c.y)*(A.c.y-B.c.y);
        int rdiff = A.r - B.r;
        int rsum = A.r + B.r;
        double base = atan2(B.c.y-A.c.y, B.c.x-A.c.x);

        if(d2 < rdiff*rdiff) return 0; //�ں�

        if(d2 == 0 && A.r == B.r) return -1;
        if(d2 == rdiff*rdiff) { //����
            a[cnt] = A.getPoint(base);
            b[cnt] = B.getPoint(base);
            ++cnt;
            return 1;
        }

        double ang = acos((A.r-B.r)/sqrt(d2));
        a[cnt] = A.getPoint(base+ang);
        b[cnt] = B.getPoint(base+ang);
        cnt++;

        a[cnt] = A.getPoint(base-ang);
        b[cnt] = B.getPoint(base-ang);
        cnt++;

        if(d2 == rsum*rsum) {
            double ang = acos((A.r+B.r)/sqrt(d2));
            a[cnt] = A.getPoint(base);
            b[cnt] = B.getPoint(pi+base);
            cnt++;
        } else if(d2 > rsum*rsum) {
            double ang = acos((A.r+B.r)/sqrt(d2));
            a[cnt] = A.getPoint(base+ang);
            b[cnt] = B.getPoint(pi+base+ang);
            cnt++;

            a[cnt] = A.getPoint(base-ang);
            b[cnt] = B.getPoint(pi+base-ang);
            cnt++;
        }

        return cnt;
    }

    Point getPoint(double a) {
        return Point(c.x+cos(a)*r, c.y+sin(a)*r);
    }

    //Բ������֮��Ļ��� a->b ��ʱ��
    double len(Point a, Point b) {
        double m1 = c.dis(a);
        double m2 = c.dis(b);
        Point v1 = a - c;
        Point v2 = b - c;
        double co = (v1^v2)/(m1*m2);
        if(v1*v2 > -eps) return r * acos(co);
        else return 2*pi*r - r * acos(co);
    }

    //Բ���ϰ���ĳ������
    bool have(double ang) {
        if(de >= db) {
            return db < ang+eps && de > ang-eps;
        } else {
            return ang > db-eps || de+eps > ang;;
        }
    }

    bool operator < (const Circle & b) const {
        if(!eq(db, b.db)) return db < b.db;
        return de < b.de;
    }

    //Բ�����
    double area() {
        return pi * r * r;
    }

    //���ε����
    double arc_area() {
        double ang = 0;
        if(de >= db) ang = de - db;
        else ang = de + 2*pi - db;
        return 0.5*r*r*(ang-sin(ang));
    }
};

struct Triangle {
    Point a, b, c;
    Triangle(){}
    Triangle(Point a, Point b, Point c): a(a), b(b), c(c){}
    //�������������
    double area() {
        return fabs(Point::xmult(a, b, c)) / 2.0;
    }
    //��������������
    //���أ����ԲԲ��
    Point circumcenter() {
        Vec2 u,v;
        u.s.x = (a.x + b.x) / 2;
        u.s.y = (a.y + b.y) / 2;
        u.e.x = u.s.x - a.y + b.y;
        u.e.y = u.s.y + a.x - b.x;
        v.s.x = (a.x + c.x) / 2;
        v.s.y = (a.y + c.y) / 2;
        v.e.x = v.s.x - a.y + c.y;
        v.e.y = v.s.y + a.x - c.x;
        return u.crossLPt(v);
    }
    //��������������
    //���أ��ڽ�ԲԲ��
    Point incenter() {
        Vec2 u, v;
        double m, n;
        u.s = a;
        m = atan2(b.y - a.y, b.x - a.x);
        n = atan2(c.y - a.y, c.x - a.x);
        u.e.x = u.s.x + cos((m + n) / 2);
        u.e.y = u.s.y + sin((m + n) / 2);
        v.s = b;
        m = atan2(a.y - b.y, a.x - b.x);
        n = atan2(c.y - b.y, c.x - b.x);
        v.e.x = v.s.x + cos((m + n) / 2);
        v.e.y = v.s.y + sin((m + n) / 2);
        return u.crossLPt(v);
    }
    //���������δ���
    //���أ��ߵĽ���
    Point perpencenter() {
        Vec2 u,v;
        u.s = c;
        u.e.x = u.s.x - a.y + b.y;
        u.e.y = u.s.y + a.x - b.x;
        v.s = b;
        v.e.x = v.s.x - a.y + c.y;
        v.e.y = v.s.y + a.x - c.x;
        return u.crossLPt(v);
    }
    //��������������
    //���أ�����
    //������������������ƽ������С�ĵ�
    //�������ڵ����߾���֮�����ĵ�
    Point barycenter() {
        Vec2 u,v;
        u.s.x = (a.x + b.x) / 2;
        u.s.y = (a.y + b.y) / 2;
        u.e = c;
        v.s.x = (a.x + c.x) / 2;
        v.s.y = (a.y + c.y) / 2;
        v.e = b;
        return u.crossLPt(v);
    }
    //���������η����
    //���أ������������������֮����С�ĵ�
    Point fermentPoint() {
        Point u, v;
        double step = fabs(a.x) + fabs(a.y) + fabs(b.x) + fabs(b.y) + fabs(c.x) + fabs(c.y);
        int i, j, k;
        u.x = (a.x + b.x + c.x) / 3;
        u.y = (a.y + b.y + c.y) / 3;
        while (step > eps)
            for (k = 0; k < 10; step /= 2, k ++)
                for (i = -1; i <= 1; i ++)
                    for (j =- 1; j <= 1; j ++)
                    {
                        v.x = u.x + step * i;
                        v.y = u.y + step * j;
                        if (u.dis(a) + u.dis(b) + u.dis(c) > v.dis(a) + v.dis(b) + v.dis(c))
                            u = v;
                    }
        return u;
    }
};

Point p[N];
double d[N];
bool is[N];
int see[N], seel;
double edgeDis[10][N];
double ts, vr, vs;
Vec2 line[N];
Point ps, pt;
vector<int> spv;
int n;
double minDisInWater, minTime, minTimeToSafe;

inline double getDis(const Point & p1, const Point & cp) {
    double timeInWater = p1.dis(pt) / vs + minTimeToSafe;
    if(timeInWater > ts + eps) return p1.dis(cp) * inf;

    return p1.dis(ps) / vr + timeInWater;
}

inline double cal(int x) {
    double minTimeInEdge = line[x].dis(pt, true) / vs + minTimeToSafe;
    if(minTimeInEdge > ts + eps) return inf;

    Point l = p[x], r = p[x+1], m1, m2, delta;
    Point cp = line[x].crossLPt(Vec2(pt, line[x].mirror(pt)));
    double dis1, dis2;
    while(r.dis(l) > eps) {
        delta = (r - l) / 3.0;
        m1 = l + delta;
        m2 = m1 + delta;
        dis1 = getDis(m1, cp);
        dis2 = getDis(m2, cp);
        if(dis1 > dis2) {
            l = m1;
        } else {
            r = m2;
        }
//        printf("l (%.3f,%.3f), r (%.3f, %.3f) d1 (%.3f,%.3f)->%.3f d2 (%.3f,%.3f)->%.3f\n", l.x, l.y, r.x, r.y, m1.x, m1.y, dis1, m2.x, m2.y, dis2);
    }
    return getDis((l + r) / 2.0, cp);
}

Point cp;
inline double getDisIs(const Point & p1, const Point & pp, const double & d) {
    double timeInWater = p1.dis(pt) / vs + minTimeToSafe;
    if(timeInWater > ts + eps) return p1.dis(cp) * inf;

    return (p1.dis(pp) + d) / vr + timeInWater;
}

inline double calis(int x) {
    double minTimeInEdge = line[x].dis(pt, true) / vs + minTimeToSafe;
    if(minTimeInEdge > ts + eps) return inf;

    cp = line[x].crossLPt(Vec2(pt, line[x].mirror(pt)));

    double ret = inf;
    double dis1, dis2;

    Point l, r, m1, m2, delta;

    double disToLeft = inf;
    rep(i, 0, spv.size()) checkmin(disToLeft, edgeDis[i][x]);
    l = p[x], r = p[(x+1)%n];
    while(l.dis(r) > eps) {
        delta = (r - l) / 3.0;
        m1 = l + delta;
        m2 = m1 + delta;
        dis1 = getDisIs(m1, p[x], disToLeft);
        dis2 = getDisIs(m2, p[x], disToLeft);
        if(dis1 > dis2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    checkmin(ret, getDisIs((l + r) / 2.0, p[x], disToLeft));

    double disToRight = inf;
    rep(i, 0, spv.size()) checkmin(disToRight, edgeDis[i][(x+1)%n]);
    l = p[x], r = p[(x+1)%n];
    while(l.dis(r) > eps) {
        delta = (r - l) / 3.0;
        m1 = l + delta;
        m2 = m1 + delta;
        dis1 = getDisIs(m1, p[x+1], disToRight);
        dis2 = getDisIs(m2, p[x+1], disToRight);
        if(dis1 > dis2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    checkmin(ret, getDisIs((l + r) / 2.0, p[x+1], disToRight));

    return ret;
}

inline void solve() {
    scanf("%lf%lf%lf", &ts, &vr, &vs);
    scanf("%lf%lf", &ps.x, &ps.y);
    scanf("%lf%lf", &pt.x, &pt.y);
    read(n);
    rep(i, 0, n) scanf("%lf%lf", &p[i].x, &p[i].y);
    if(sgn((p[1]-p[0])*(p[2]-p[1])) < 0) {
        reverse(p, p + n);
    }
    p[n] = p[0];
    minDisInWater = inf;
    rep(i, 0, n) {
        line[i] = Vec2(p[i], p[i+1]);
        checkmin(minDisInWater, line[i].dis(pt, true));
    }
    minTime = (minDisInWater / vs) * 3;
    minTimeToSafe = (minDisInWater / vs) * 2;
    if(minTime > ts + eps) {
        puts("-1");
        return;
    }
    seel = 0;
    rep(i, 0, n) {
        if(sgn((p[i+1]-p[i])*(ps-p[i+1]) > 0)) {
            is[i] = true;
        }
        else {
            is[i] = false;
            see[seel++] = i;
        }
    }
//    printf("seel %d\n", seel);
    spv.clear();
    spv.pb(see[0]);
    spv.pb((see[seel-1] + 1)%n);
    rep(i, 0, seel-1) if(see[i+1] != see[i] + 1) {
        spv.pb((see[i] + 1)%n);
        spv.pb(see[i+1]);
    }
//    for(auto & it : spv) printf("spv %d\n", it);

    double totLen = 0;
    rep(i, 0, n) {
        d[i] = p[i+1].dis(p[i]);
        totLen += d[i];
    }
    rep(i, 0, spv.size()) {
        double cur = 0;
        int x = spv[i];
        rep(j, 0, n) {
            edgeDis[i][(x+j)%n] = min(cur, totLen - cur) + ps.dis(p[x]);
            cur += d[(x+j)%n];
        }
    }
    double ans = inf;
    rep(i, 0, n) {
        if(is[i]) {
            checkmin(ans, calis(i));
//            printf("edge %d -> %.3f\n", i, calis(i));
        } else {
            checkmin(ans, cal(i));
//            printf("edge %d -> %.3f\n", i, cal(i));
        }
    }
    printf("%.2f\n", ans);
}

int main() {
    int T;
    read(T);
    while(T--) solve();

    return 0;
}
