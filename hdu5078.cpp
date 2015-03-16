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
int T,n,i,j;
double t[1100],x[1100],y[1100];
double dis(double x,double y,double x1,double y1)
{
	return sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		double ans=0;
		for (i=1;i<=n;i++)
			scanf("%lf%lf%lf",&t[i],&x[i],&y[i]);
		for (i=1;i<n;i++)
			for (j=i+1;j<=n;j++)
			{
				double s=dis(x[i],y[i],x[j],y[j])/(t[j]-t[i]);
				if (ans<s) ans=s;
			}
		printf("%.9lf\n",ans);
	}
	return 0;
}
