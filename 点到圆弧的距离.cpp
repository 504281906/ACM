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
double X0,X1,X2,X3,px,py,Y0,Y1,Y2,Y3,R;
int flag;
struct point
{
	double x,y;
	point (double x=0,double y=0):x(x),y(y){}
};
int dcmp(double x)
{
	if (fabs(x)<eps) return 0;
	else return x<0?-1:1;
}
double findy(double x)
{
	double ans=0;
	ans=sqrt(R-(x-X0)*(x-X0))+Y0;
	return ans;
}
double dis(double x,double y,double xx,double yy)
{
	return sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
}
int sfun(point a,point b,point c)
{
	int ans=(a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
	if (ans>0) return 1;
	if (ans<0) return -1;
	if (ans==0) return 0;
}
point go(point v,point l,point r)
{
	if (X0==v.x && Y0==v.y)
	{
		point p1,p2;
		p1=point(l.y-v.y+v.x,l.x-v.x+v.y);
		p2=point(l.y-v.y+v.x,v.x-l.x+v.y);
		if (sfun(l,r,p1)==flag)
			return p1;
		else return p2;
	}
	else
	{
		double gg=dis(v.x,v.y,X0,Y0);
		double gg1=sqrt(R);
		l.x=X0+(v.x-X0)/gg*gg1;
		l.y=Y0+(v.y-Y0)/gg*gg1;
	//	point rr=point(X0,Y0);
	//	if (sfun(rr,l,v)==0) cout<<"%%%"<<endl;
		return l;
	}
}
int main()
{
	int cas=1;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2,&X3,&Y3,&px,&py))
	{
		double k,k1,g,g1,z,z1,a,b,a1,b1;
		k=2*(X1-X2);k1=2*(X1-X3);
		g=2*(Y1-Y2);g1=2*(Y1-Y3);
		z=Y1*Y1+X1*X1-X2*X2-Y2*Y2;
		z1=Y1*Y1+X1*X1-X3*X3-Y3*Y3;
		a=k/g;b=z/g;
		a1=k1/g1;b1=z1/g1;
		if (k==0)
		{
			Y0=z/g;
			X0=(z1-g1*Y0)/k1;
		}
		else if (k1==0)
		{
			Y0=z1/g1;
			X0=(z-g*Y0)/k;
		}
		else if (g==0)
		{
			X0=z/k;
			Y0=(z1-k1*X0)/g1;
		}
		else if (g1==0)
		{
			X0=z1/k1;
			Y0=(z-k*X0)/g;
		}
		else
		{
			X0=(b1-b)/(a1-a);
			Y0=(z-k*X0)/g;
		}
		R=(X1-X0)*(X1-X0)+(Y1-Y0)*(Y1-Y0);
		point l=point(X1,Y1);
		point r=point(X3,Y3);
		point zh=point(X2,Y2);
		flag=sfun(l,r,zh);
		double ans=0x3fffffff;
		int w1=0,w2=0,w3=0;
		w1=dis(X0,Y0,l.x,l.y);
		w2=dis(X0,Y0,r.x,r.y);
		w3=dis(X0,Y0,zh.x,zh.y);
		double rr=sqrt(R);
	//	cout<<w1<<w2<<w3<<endl;
	//	if (w1-rr<=eps && w2-rr<=eps && w3-rr<=eps) cout<<"YES"<<endl;
		while (dis(l.x,l.y,r.x,r.y)>eps)
		{
			point v=point((l.x+r.x)/2,(l.y+r.y)/2);
			point mid=go(v,l,r);
			double gl=dis(l.x,l.y,px,py);
			double gr=dis(r.x,r.y,px,py);
			if (gl>=gr)
			{
				if (ans-gr>eps)
					ans=gr;
				l.x=mid.x;
				l.y=mid.y;
			}
			else
			{
				if (ans-gl>eps)
					ans=gl;
				r.x=mid.x;
				r.y=mid.y;
			}
		}
		printf("Case %d: %lf\n",cas++,ans);
	}
	return 0;
}
