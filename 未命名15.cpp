#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>

using namespace std;

const int N = 40005;

typedef double DIY;

struct Point
{
    DIY x,y;
};

Point p[N];
Point stack[N];
Point MinA;

int top;

DIY dist(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

DIY cross(Point A,Point B,Point C)
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}

bool cmp(Point a,Point b)
{
    DIY k=cross(MinA,a,b);
    if(k>0) return 1;
    if(k<0) return 0;
    return dist(MinA,a)<dist(MinA,b);  //这里共线的点按距离从小到大排序
}

void Graham(int n)
{
    int i;
    for(i=1; i<n; i++)
        if(p[i].y<p[0].y||(p[i].y==p[0].y&&p[i].x<p[0].x))
            swap(p[i],p[0]);
    MinA=p[0];
    sort(p+1,p+n,cmp);
    stack[0]=p[0];
    stack[1]=p[1];
    top=1;
    for(i=2; i<n; i++)
    {
        //注意这里我们把共线的点也压入凸包里
        while(cross(stack[top-1],stack[top],p[i])<0&&top>=1) --top;
        stack[++top]=p[i];
    }
}

bool Judge()
{
    for(int i=1;i<top;i++)
    {
        //判断凸包的一条边上是否至少有3点
        if((cross(stack[i-1],stack[i+1],stack[i]))!=0&&(cross(stack[i],stack[i+2],stack[i+1]))!=0)
            return false;
    }
    return true;
}

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        if(n<6)
        {
            puts("NO");
            continue;
        }
        Graham(n);
        cout<<endl;
        for(i=0;i<n;i++)
          cout<<p[i].x<<" "<<p[i].y<<endl;
        cout<<endl;
        for(i=0;i<=top;i++)
          cout<<stack[i].x<<" "<<stack[i].y<<endl;
        if(Judge()) puts("YES");
        else        puts("NO");
    }
    return 0;
}

