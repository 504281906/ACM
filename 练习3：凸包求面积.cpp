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
using namespace std;
#define ling 1e-10
#define pi acos(-1)
struct point
{
	int x,y;
}p[10010],f[10010];
double mul(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp(point a,point b)
{
	double k=mul(p[0],a,b);
	if (k<-ling)
		return 0;
	if (fabs(k)<=ling && dis(p[0],a)-dis(p[0],b)>ling)
		return 0;
	return 1;
}
int main()
{
	int n,i,t,m;
	while (~scanf("%d",&n))
	{
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			if (i==0) t=0;
			else
			if (p[t].y>p[i].y)
				t=i;
			else
			if (p[t].y==p[i].y && p[t].x>p[t].x)
				t=i;
		}
		point h=p[t];
		p[t]=p[0];
		p[0]=h;
		sort(p+1,p+n,cmp);
		int l=1,j=1;
		f[0]=p[n-1];
		f[1]=p[0];
		while (l<n)
		{
			double k=mul(p[l],f[j-1],f[j]);
			if (k>ling)
				f[++j]=p[l++];
			else j--;
		}
		//求凸包周长
	/*	double s=dis(f[0],f[j]);
		for (i=1;i<=j;i++)
			s+=dis(f[i-1],f[i]);
		printf("%d\n",(int)(s+(2*pi*m+0.5)));*/
		//求凸包面积
		double ans=0;
		for (i=1;i<=j;i++)
		{
			double k=mul(f[0],f[i],f[i+1]);
			ans+=k;
		}
		ans=fabs(ans)/2;
		printf("%d\n",(int)(ans/50));
	} 
	return 0;
}
