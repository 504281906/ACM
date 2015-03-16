#include <stdio.h>
#include <cstdlib>
#include <cmath>
#define N 1005
#define inf 1e-8
#define PI 3.141592653589793
typedef struct
{
    int x;
    int y;
}point;
point points[N]; //点集
point chs[N];     //栈
int sp; //栈顶指针
//计算两点之间距离
double dis(point a, point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) * 1.0 + (a.y - b.y) * (a.y - b.y));
}
//通过矢量叉积求极角关系（p0p1）(p0p2)
//k > 0 ,p0p1在p0p2顺时针方向上
double multi(point p0, point p1, point p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int cmp(const void *p, const void *q)
{
    point a = *(point *)p;
    point b = *(point *)q;
    double k = multi(points[0], a, b);
    if(k < -inf)
        return 1;
    else if(fabs(k) < inf && (dis(a, points[0]) - dis(b, points[0])) > inf) //两点在同一直线上的话，用最近的
        return 1;
    else return -1;
}
void convex_hull(int n)
{
    int i, k, d;
    int miny = points[0].y, index = 0;
    for(i=1; i<n; i++) //找最左下顶点
    {
        if(points[i].y < miny) //找到y坐标最小的点
        {
            miny = points[i].y;
            index = i;
        }
        else if(points[i].y == miny && points[i].x < points[index].x) //相同的话找到x最小的
        {
            index = i;
        }
    }
    //把最左下顶点放到第一个
    point temp;
    temp = points[index];
    points[index] = points[0];
    points[0] = temp;
    qsort(points+1, n-1, sizeof(points[0]), cmp); //p[1:n-1]按相对p[0]的极角从小到大排序
    chs[0] = points[n-1];
    chs[1] = points[0];
    sp = 1;
    k = 1;
    while(k <= n-1)
    {
        double d = multi(chs[sp], chs[sp-1], points[k]);
        if(d <= 0)
        {
            sp++;
            chs[sp] = points[k];
            k++;
        }
        else sp--;
    }
}
int main()
{
    int i,n,dist;
    double sum;
    //freopen("input", "r", stdin);
    scanf("%d %d", &n,&dist);
    for(i=0; i<n; i++)
        scanf("%d %d",&points[i].x,&points[i].y);
    convex_hull(n);
    sum = 0;
    for(i=1; i<=sp; i++) //求周长
        sum += dis(chs[i-1], chs[i]);
    sum += dis(chs[0], chs[sp]);
    printf("%d",(int)(sum+2*PI*dist+0.5));
    return 0;
}
