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
struct point{
	int k;
	double x,y;
	point(){}
	point(int k,double x,double y):k(k),x(x),y(y){}
};
double cross(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
point operator -(point a,point b)
{
	return point(0,a.x-b.x,a.y-b.y);
}
int pd(point a,point b,point c)
{
	if (cross(b-a,c-a)<0) return 1;
	if (fabs(cross(b-a,c-a))<eps && dis(a,c)-dis(a,b)<0) return 1;
	return 0;
}
point p[110];
int vis[110];
int main()
{
	int T,i,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		point pp=point(0,110.0,110.0);
		for (i=1;i<=n;i++){
			scanf("%d%lf%lf",&p[i].k,&p[i].x,&p[i].y);
			vis[i]=0;
			if (pp.y>p[i].y){
				if (pp.y>p[i].y)
					pp=p[i];
				else if (pp.x>p[i].x)
					pp=p[i];
			}
		}	
		cout<<n;
		cout<<" "<<pp.k;
		vis[pp.k]=1;
		point p1;
		int f;
		int m=n-1;
		while (m--){
			f=1;
			for (i=1;i<=n;i++)
				if (!vis[i]){
					if (f){
						p1=p[i];
						f=0;
					}
					else if (pd(pp,p1,p[i]))
						p1=p[i];
				}
			vis[p1.k]=1;
			cout<<" "<<p1.k;
			pp=p1;
		}
		cout<<endl;
	}
	return 0;
}
