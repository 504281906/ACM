#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define ling 1e-10
int ds,n;
struct point 
{
	int x,y;
}p[110];
point pp[110];
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
	if (k<ling)
		return 0;
	if (fabs(k)<ling && (dis(p[0],a)-dis(p[0],b)>ling) )
		return 0;
	else
		return 1;
}
void ff(int n)
{
	int i,j=0;
	point k=p[0];
	for (i=1;i<n;i++)
	{
		if (k.y>p[i].y)
		{
			j=i;
			k=p[i];
		}
		else 
		if (k.y==p[i].y && k.x>p[i].x)
		{
			j=i;
			k=p[i];
		}
	}
	k=p[0];
	p[0]=p[j];
	p[j]=k;
	sort(p+1,p+n,cmp);
	ds=1;
	int l=1;
	pp[0]=p[n-1];
	pp[1]=p[0];
	while (l<n)
	{
		double d=fff(pp[ds],pp[ds-1],p[l]);
		if (d<=ling)
		{
			ds++;
			pp[ds]=p[l];
			l++;
		}
		else 
			ds--;
	}
}
int main()
{
	while (~scanf("%d",&n) && n)
	{
		for (int i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		if (n==2)
		{
			printf("%.2lf\n",dis(p[0],p[1]));
			continue;
		}
		ff(n);
		double s=0;
		for (int i=1;i<=ds;i++)
			s+=dis(pp[i-1],pp[i]);
		s+=dis(pp[0],pp[ds]);
		printf("%.2lf\n",s);
	}
	return 0;
}
