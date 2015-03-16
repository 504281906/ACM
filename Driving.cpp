#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define ling 1e-8
#define INF 0x3fffffff
using namespace std;
double s[100010],b[100010];
int main()
{
	int n,i;
	double f,v;
	while (scanf("%d",&n)==1)
	{
		scanf("%lf%lf",&f,&v);
		for (i=1;i<=n;i++)
			scanf("%lf%lf",&s[i],&b[i]);
		double ans=INF,l=0,r=v;
		int find=0;
		while (r-l>ling)
		{
			double qy=0,t=0;
			double mid=(r+l) / 2.0;
			for (i=1;i<=n;i++)
			{
				if (b[i]>=0)
				{
					qy+=(0.5*mid+b[i])*s[i];
					t+=s[i]/mid;
				}
				else
				{
					qy+=max(0.0,0.5*mid+b[i])*s[i];
					if ((0.5*mid+b[i])>=ling)
						t+=s[i]/mid;
					else
						t+=s[i]/min(v,-b[i]/0.5);
				}
				if (qy>f) break;
			}
			if (qy<f)
			{
				find=1;
				l=mid;
				ans=min(ans,t);
			}
			else
				r=mid;
		}
		if (find)
			printf("%.3lf\n",ans);
		else
			printf("Bad Luck!\n");
	}
	return 0;
}
