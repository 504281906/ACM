#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm> 
using namespace std;
#define ling 1e-10
#define pi 3.1415926535 
int sp;
struct point 
{
	int x,y;
}p[1010];
point pp[1010];
double dis(point a,point b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y) );
}
double fff(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
bool cmp(point a,point b)
{
	double k=fff(p[0],a,b);
	if (k<-ling)
		return false;
	else if (fabs(k)<ling && (dis(a,p[0])-dis(b,p[0])>ling))
		return false;	
	else return true;
}
int ff(int n)
{
	int i,j=0;
	point k=p[0];
	for (i=1;i<n;i++)
	{
		if (k.y>p[i].y)
		{
			k=p[i];
			j=i;
		}
		else 
		if (k.y==p[i].y && k.x>p[i].x)
		{
			k.x=p[i].x;
			j=i;
		}
	}
	point t;
	t=p[0];
	p[0]=p[j];
	p[j]=t;
	sort(p+1,p+n,cmp);
	pp[0]=p[n-1];
	pp[1]=p[0];
    sp=1;
	int l=1;
	while (l<=n-1)
	{
		double d=fff(pp[sp-1],pp[sp],p[l]);
		if(d > ling)
		{
			sp++;
			pp[sp]=p[l];
			l++;
		}
		else sp--;
	}
}
int main()
{
	int n,m,T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		ff(n);
		double s=0;
		for (int i=1;i<=sp;i++)
			s+=dis(pp[i-1],pp[i]);
	//	s+=dis(pp[0],pp[sp]);
		printf("%d\n",(int)s);
		s+=2*pi*(double)m+0.5;
		printf("%d\n",(int)s);
		if (T) printf("\n");
	}
	return 0;
}
