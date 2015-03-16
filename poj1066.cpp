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
	point(){}
	point(double x,double y):x(x),y(y){}
};
struct line
{
	point a,b;
};
point p[200];
line l[100];
double cross(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp(point a,point b)
{
	double k=cross(p[0],a,b);
	if (fabs(k)<=eps)
		if (a.y==0 && b.y==0)
		{
			if (dis(p[0],a)-dis(p[0],b)>eps)
				return 0;
		}
		else
		{
			if (dis(p[0],b)-dis(p[0],a)>eps)
				return 0;
		}
	if (k<0)
		return 0;
	return 1;
}                   //极角排序 机智的我！ 
point newp(point a,point b)
{
	point c=point((a.x+b.x)/2,(a.y+b.y)/2);
	return c;
}
int pd(point a,point b,point c,point d)
{
	double k1=cross(a,b,c),k2=cross(a,b,d);
	double k3=cross(c,d,b),k4=cross(c,d,a);
	if (k1*k2<0 && k3*k4<0) return 1;
	return 0;
}
int main()
{
	int n,i,j;
	double x1,x2,y1,y2,x,y;
	while (~scanf("%d",&n))
	{
		memset(p,0,sizeof(p));
		memset(l,0,sizeof(l));
		int t=1;
		p[0].x=0;p[0].y=0;
		for (i=1;i<=n;i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			p[t].x=x1;p[t++].y=y1;
			p[t].x=x2;p[t++].y=y2;
			l[i].a=p[t-2];
			l[i].b=p[t-1];
		}
		t--;
		sort(p+1,p+1+t,cmp);
		//cout<<cross(p[0],p[1],p[2])<<endl;
		/*for (i=0;i<=t;i++)
			cout<<p[i].x<<" "<<p[i].y<<endl;*/
		point o;
		scanf("%lf%lf",&o.x,&o.y);
		point pp=newp(p[1],p[t]);
		line ll;
		ll.a=pp;
		ll.b=o;
		int ans=0;
		for (i=1;i<=n;i++)
			if (pd(ll.a,ll.b,l[i].a,l[i].b))
				ans++;
		for (i=2;i<=t;i++)
		{
			pp=newp(p[i-1],p[i]);
			ll.a=pp;
			ll.b=o;
			int temp=0;
			for (j=1;j<=n;j++)
				if (pd(ll.a,ll.b,l[j].a,l[j].b))
					temp++;
			if (temp<ans)
				ans=temp;
		}
		//for (i=1;i<=ans;i++)
		printf("Number of doors = %d\n",ans+1);
	}
	return 0;
}
