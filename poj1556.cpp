#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#include <ctime>
#define LL __int64
#define eps 1e-8
using namespace std;
struct point 
{
	double x,y;
	point (){}
	point (double x,double y):x(x),y(y){}
};
struct line
{
	point a,b;
	line(){};
};
point operator -(point a,point b)
{
	return point(a.x-b.x,a.y-b.y);
}
int n;
double d[222][222];
line l[100][5];
point p[111][5];
double cross(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
int pd1(point a,point b,point c,point d)
{
	double k1=cross(a-c,b-c);
	double k2=cross(a-d,b-d);
	if (k1*k2<=0 || fabs(k1*k2)<eps) return 1;
	else return 0;
}
int pd(point a,point b,int begin,int end)
{
	for (int i=begin+1;i<end;i++)
		for (int j=1;j<=3;j++)
			if (pd1(a,b,l[i][j].a,l[i][j].b)) return 0;
	return 1;
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void gg()
{
	int i,j,k,k1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=4;j++)
		{
			if (pd(p[0][1],p[i][j],0,i))
				d[i][j]=dis(p[0][1],p[i][j]);
			else 
			{
				d[i][j]=500000.0;
				for (k=1;k<i;k++)
					for (k1=1;k1<=4;k1++)
					{
						if (pd(p[k][k1],p[i][j],k,i))
							if (d[k][k1]+dis(p[i][j],p[k][k1])<=d[i][j])
								d[i][j]=d[k][k1]+dis(p[i][j],p[k][k1]);
					}
			}
		}
	}
	double ans=500000.0;
	for (i=1;i<=n;i++)
		for (j=1;j<=4;j++)
			if (pd(p[i][j],p[n+1][1],i,n+1))
				if (d[i][j]+dis(p[i][j],p[n+1][1])<=ans)
					ans=d[i][j]+dis(p[i][j],p[n+1][1]);
	printf("%.2lf\n",ans);
}
int main()
{
	double x,y1,y2,y3,y4;
	while (~scanf("%d",&n) && n!=-1)
	{
		memset(p,0,sizeof(p));
		memset(l,0,sizeof(l));
		p[0][1].x=0;p[0][1].y=5.0;
		p[n+1][1].x=10;p[n+1][1].y=5.0;
		for (int i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf%lf",&x,&y1,&y2,&y3,&y4);
			p[i][1].x=x;p[i][1].y=y1;
			p[i][2].x=x;p[i][2].y=y2;
			p[i][3].x=x;p[i][3].y=y3;
			p[i][4].x=x;p[i][4].y=y4;
			l[i][1].a=point(x,0);l[i][1].b=point(x,y1);
			l[i][2].a=point(x,y2);l[i][2].b=point(x,y3);
			l[i][3].a=point(x,y4);l[i][3].b=point(x,10.0);
		}
		memset(d,0,sizeof(d));
		if (pd(p[0][1],p[n+1][1],0,n+1))
		{
			printf("%.2lf\n",dis(p[0][1],p[n+1][1]));
			continue;
		}
		else gg();
	}
	return 0;
}
