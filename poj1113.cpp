#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define ling 1e-10
#define pi 3.1415926
int begin;
struct point 
{
	int x,y;
}p[1010];
point pp[1010];
double dis(point a,point b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}
double fff(point a,point b,point c)
{
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
bool cmp(point a,point b)
{
	double k=fff(a,b,p[0]);
	if (k<-ling)
		return false;
	else if (fabs(k)<ling && ( dis(a,p[0])-dis(b,p[0])>ling ))
		return false;
	return true;
}
int ff(int n)
{
	int i,j,k=0;
	for (i=1;i<n;i++)
		if (p[k].y>p[i].y || (p[k].y==p[i].y && p[k].x>p[i].x))
			k=i;
	point t;
	t=p[k];
	p[k]=p[0];
	p[0]=t;
	sort(p+1,p+n,cmp);
	pp[0]=p[n-1];
	pp[1]=p[0];
	begin=1;
	int l=1;
	while (l<=n-1)
	{
		double d=fff(pp[begin-1],pp[begin],p[l]);
		if (d>ling)
		{
			begin++;
			pp[begin]=p[l];
			l++;
		}
		else begin--;
	}
}
int main()
{
	int n,m,T,i;
	while (~scanf("%d%d",&n,&m))
	{
		for (i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		ff(n);
		double s=0;
		for (i=1;i<=begin;i++)
			s+=dis(pp[i-1],pp[i]);
		s+=dis(pp[0],pp[begin]);
		//printf("%d\n",(int)s);
		s+=2*pi*(double)m+0.5;
		printf("%d\n",(int)s);
		if (T) printf("\n");
	}
	return 0;
} 
