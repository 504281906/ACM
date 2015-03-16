#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
	double x,y;
}p[10010];
int f[10010];
int cmp1(point a,point b)
{
	return a.x<b.x;
}
int cmp2(int a,int b)
{
	return p[a].y<p[b].y;
}
double dis(int a,int b)
{
	return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)+(p[a].y-p[b].y)*(p[a].y-p[b].y));
}
double ff(int l,int r)
{
	int i,j;
	if (l==r) return 0x3fffffff;
	if (l+1==r) return dis(l,r);
	int mid=(l+r)/2;
	double d=min(ff(l,mid),ff(mid+1,r));
	int k=0;
	for (i=l;i<=r;i++)
		if (fabs(p[i].x-p[mid].x)<d)
			f[k++]=i;
	sort(f,f+k,cmp2);
	for (i=0;i<k;i++)
		for (j=i+1;j<k && p[f[j]].y-p[f[i]].y<d;j++)
		if (d-dis(f[i],f[j])>1e-9 ) d=dis(f[i],f[j]);
	return d;
}
int main()
{
	int n,i;
	while (~scanf("%d",&n) && n)
	{
		for (i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		sort(p,p+n,cmp1);
		double m=ff(0,n-1);
		if (m-10000 <=1e-9) printf("%.4lf\n",m);
		else cout<<"INFINITY"<<endl;
	} 
	return 0;
}
