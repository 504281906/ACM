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
}f[1000];
double dis(point a,point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double mul(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
int main()
{
	int T,n,i;
	double a,b;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%lf%lf",&f[i].x,&f[i].y);
		scanf("%lf%lf",&a,&b);
		double c=0,s=0,ans=a*dis(f[1],f[n]);
		for (i=2;i<=n;i++)
		{
			c=dis(f[i],f[i-1]);
			ans+=c*a;
			if (i>=3)
				s+=mul(f[1],f[i-1],f[i]);
		}
		s=fabs(s)/2;
		cout<<s<<endl;
		ans+=s*b;
		printf("%.6lf\n",ans);
	}
	return 0;
}
