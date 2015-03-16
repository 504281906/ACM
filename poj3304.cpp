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
}l[200],r[200],p[210];
double across(point a,point b,point c)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
int go(point a,point b,point c,point d)
{
	double ans=across(a,b,c)*across(a,b,d);
	if (ans<0 || fabs(ans)<eps) return 1;
	else return 0;
}
int main()
{
	int T,i,j,k,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		int cnt=0;
		for (i=1;i<=n;i++){
			scanf("%lf%lf%lf%lf",&l[i].x,&l[i].y,&r[i].x,&r[i].y);
			p[cnt].x=l[i].x;p[cnt++].y=l[i].y;
			p[cnt].x=r[i].x;p[cnt++].y=r[i].y;
		}
		int flag=1;
		for (i=0;i<cnt && flag;i++){
			for (j=i+1;j<cnt && flag;j++){
				if (p[i].x==p[j].x && p[i].y==p[j].y) continue;
				int ff=1;
				for (k=1;k<=n;k++){
					if (!go(p[i],p[j],l[k],r[k])){
						ff=0;
						break;
					}
				}
				if (ff) flag=0;
			}
		}
		if (flag) cout<<"No!"<<endl;
		else cout<<"Yes!"<<endl;
	}
	return 0;
}
