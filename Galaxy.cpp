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
double a[500010];
int T,n,k,i,j;
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		sort(a+1,a+1+n);
		int g=n-k;
		if (g<=1) 
		{
			printf("0\n");
			continue;
		}
		double s=0;
		for (i=1;i<=g;i++)
			s+=a[i];
		double ans=0x3fffffff;
		for (i=1;i<=k+1;i++)
		{
			double pos=s/g;
			double mm=0;
			for (j=i;j<=g+i-1;j++)
			{
				mm+=(a[j]-pos)*(a[j]-pos);
				if (mm-ans>eps) break;
			}
			if (ans-mm>eps) ans=mm;
			s=s-a[i]+a[g+i];
		}
		printf("%.9lf\n",ans);
	}
	return 0;
}
