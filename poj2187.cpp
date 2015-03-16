#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
struct point 
{
	int x,y;
}p[50010],pp[50010];
int n,m;
int dis(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int fff(point a,point b,point c)
{
	return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x) );
}
bool cmp(point a,point b)
{
	if (fff(p[0],a,b)>0) return 1;
	if (fff(p[0],a,b)<0) return 0;
	if (fff(p[0],a,b)==0 && (dis(p[0],a)-dis(p[0],b))>0) return 0;
	else return 1;
}
void ff(int n)
{
	int i,j=0;
	for (i=1;i<n;i++)
		if (p[j].y>p[i].y || (p[j].y==p[i].y && p[j].x>p[i].x))
			j=i;
	point k=p[0];
	p[0]=p[j];
	p[j]=k;
	sort(p+1,p+n,cmp);
	pp[0]=p[0];pp[1]=p[1];
	m=1;
	for (i=2;i<n;i++)
	{
		while ( fff(pp[m],pp[m-1],p[i])>0 )
		{
			if (m==0) break;
			m--;
		}
		pp[++m]=p[i];
	}
}
int main()
{
	while (~scanf("%d",&n))
	{
		int i,j,t;
		bool flag=true;
		p[-1].x=0;p[-1].y=0;
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			if (i==0) t=fff(p[-1],p[i-1],p[i]);
			else 
			if (t!=fff(p[-1],p[i-1],p[i])) flag=false; 
		}
		double s=0;
		if (flag)
		{
			for (i=0;i<n-1;i++)
			for (j=i+1;j<n;j++)
				if (s<dis(p[i],p[j]))
					s=dis(p[i],p[j]);
			printf("%d\n",(int)s);
			continue;
		}
		ff(n);
		for (i=0;i<m;i++)
			for (j=i+1;j<=m;j++)
				if (s<dis(pp[i],pp[j]))
					s=dis(pp[i],pp[j]);
		printf("%d\n",(int)s);
	}
	return 0;
}
