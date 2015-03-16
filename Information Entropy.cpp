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
double a[110],b;
int T,i,n;
char s[10];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d %s",&n,&s);
		if (s[0]=='b')
			b=2;
		else if (s[0]=='n')
			b=exp(1);
		else b=10;
		double ans=0;
		for (i=1;i<=n;i++)
		{
			scanf("%lf",&a[i]);
			if (fabs(a[i])<=eps) continue;
			a[i]/=100;
			ans+=a[i]*(log(a[i])/log(b));
		}
		printf("%.12lf\n",-ans);
	}
	return 0;
}
