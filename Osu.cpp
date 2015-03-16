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
#define EPS 1e-8
using namespace std;
double a[100];
int cmp(double a,double b)
{
	return a>b;
}
int main()
{
	int T,i,n;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		double s=0;
		for (i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		sort(a+1,a+1+n,cmp);
		double t=1;
		double ans=0;
		for (i=1;i<=n;i++)
		{
			ans+=a[i]*t;
			t*=0.95;
		}
		printf("%lf\n",ans);
	}
	return 0;
}

