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
#define LL __int64
double ksm(double a,int b)
{
	double ans=1;
	while (b!=0)
	{
		if (b & 1)
			ans*=a;
		b>>=1;
		a*=a;
	}
	return ans;
}
int main()
{
	int n,m,i;
	scanf("%d%d",&m,&n);
	double ans=0;
	for (i=1;i<=m;i++)
	{
		double pre=ksm((i-1)*1.0/m,n);
		double now=ksm(i*1.0/m,n);
		ans+=(now-pre)*i;
		pre=now;
	}
	printf("%.12lf\n",ans);
	return 0;
}
